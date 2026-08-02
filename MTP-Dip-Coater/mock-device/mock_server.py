from fastapi import FastAPI, WebSocket, WebSocketDisconnect
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel
import asyncio
import time
import math
import json

app = FastAPI(title="Dip Coater Mock Device Service")

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# Simulated Machine State
class MachineState:
    def __init__(self):
        self.state = "idle"  # idle, homing, moving, dwelling, error
        self.x = 0.0
        self.y = 0.0
        self.target_x = 0.0
        self.target_y = 0.0
        self.current_command = "NONE"
        self.error_code = 0
        self.error_message = ""
        self.cancel_event = asyncio.Event()

    def get_status(self):
        return {
            "state": self.state,
            "position": {
                "x": round(self.x, 2),
                "y": round(self.y, 2)
            },
            "current_command": self.current_command,
            "error_code": self.error_code,
            "error_message": self.error_message
        }

machine = MachineState()

class MoveParams(BaseModel):
    x: float
    y: float
    speed: float  # mm/s
    accel: float  # mm/s^2

class DwellParams(BaseModel):
    duration_ms: int

# --- SIMULATOR PHYSICS ---

async def simulate_homing():
    machine.state = "homing"
    machine.current_command = "HOME"
    machine.cancel_event.clear()
    
    # Simulate moving slowly back to (0.0, 0.0) from current position
    steps = 20
    dx = -machine.x / steps
    dy = -machine.y / steps
    
    for _ in range(steps):
        if machine.cancel_event.is_set():
            return
        machine.x += dx
        machine.y += dy
        await asyncio.sleep(0.1) # 100ms per step

    machine.x = 0.0
    machine.y = 0.0
    machine.state = "idle"
    machine.current_command = "NONE"

async def simulate_movement(params: MoveParams):
    machine.state = "moving"
    machine.current_command = "MOVE"
    machine.cancel_event.clear()
    
    machine.target_x = params.x
    machine.target_y = params.y
    
    start_x, start_y = machine.x, machine.y
    distance = math.sqrt((params.x - start_x)**2 + (params.y - start_y)**2)
    
    if distance < 0.01:
        machine.x = params.x
        machine.y = params.y
        machine.state = "idle"
        machine.current_command = "NONE"
        return

    # Duration of movement calculated by speed
    duration = distance / params.speed
    steps = int(duration * 10)  # 10 Hz updates
    if steps < 1:
        steps = 1
        
    step_duration = duration / steps
    dx = (params.x - start_x) / steps
    dy = (params.y - start_y) / steps

    for _ in range(steps):
        if machine.cancel_event.is_set():
            return
        machine.x += dx
        machine.y += dy
        await asyncio.sleep(step_duration)

    machine.x = params.x
    machine.y = params.y
    machine.state = "idle"
    machine.current_command = "NONE"

async def simulate_dwell(params: DwellParams):
    machine.state = "dwelling"
    machine.current_command = "DWELL"
    machine.cancel_event.clear()
    
    duration_sec = params.duration_ms / 1000.0
    steps = int(duration_sec * 10)
    step_duration = 0.1
    
    if steps <= 0:
        await asyncio.sleep(duration_sec)
    else:
        for _ in range(steps):
            if machine.cancel_event.is_set():
                return
            await asyncio.sleep(step_duration)

    machine.state = "idle"
    machine.current_command = "NONE"

def halt_machine():
    machine.cancel_event.set()
    machine.state = "idle"
    machine.current_command = "NONE"

# --- HTTP ENDPOINTS ---

@app.get("/status")
def get_status():
    return machine.get_status()

@app.post("/home")
def trigger_home():
    if machine.state != "idle":
        return {"status": "error", "message": f"Machine busy in state: {machine.state}"}
    asyncio.create_task(simulate_homing())
    return {"status": "success", "message": "Homing initiated"}

@app.post("/move")
def trigger_move(params: MoveParams):
    if machine.state != "idle":
        return {"status": "error", "message": f"Machine busy in state: {machine.state}"}
    asyncio.create_task(simulate_movement(params))
    return {"status": "success", "message": "Move initiated"}

@app.post("/dwell")
def trigger_dwell(params: DwellParams):
    if machine.state != "idle":
        return {"status": "error", "message": f"Machine busy in state: {machine.state}"}
    asyncio.create_task(simulate_dwell(params))
    return {"status": "success", "message": "Dwell initiated"}

@app.post("/stop")
def trigger_stop():
    halt_machine()
    return {"status": "success", "message": "Machine halted"}

# --- WEBSOCKET CONNECTION AND CONTROL ---

@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()
    
    async def send_status_loop():
        try:
            while True:
                await websocket.send_json(machine.get_status())
                await asyncio.sleep(0.2)  # Broadcast 5 times a second
        except Exception:
            pass

    # Start telemetry sender
    status_task = asyncio.create_task(send_status_loop())
    
    try:
        while True:
            # Receive commands over WebSocket
            data = await websocket.receive_text()
            try:
                cmd_packet = json.loads(data)
                cmd = cmd_packet.get("command")
                
                if cmd == "HOME":
                    if machine.state == "idle":
                        asyncio.create_task(simulate_homing())
                elif cmd == "MOVE":
                    if machine.state == "idle":
                        params = MoveParams(**cmd_packet.get("params", {}))
                        asyncio.create_task(simulate_movement(params))
                elif cmd == "DWELL":
                    if machine.state == "idle":
                        params = DwellParams(**cmd_packet.get("params", {}))
                        asyncio.create_task(simulate_dwell(params))
                elif cmd == "STOP":
                    halt_machine()
                elif cmd == "STATUS":
                    await websocket.send_json(machine.get_status())
            except Exception as e:
                await websocket.send_json({"error": "invalid_command", "details": str(e)})
    except WebSocketDisconnect:
        pass
    finally:
        status_task.cancel()
