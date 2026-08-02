from contextlib import asynccontextmanager
from typing import List, Dict, Set
from fastapi import FastAPI, Depends, HTTPException, status, WebSocket, WebSocketDisconnect
from fastapi.middleware.cors import CORSMiddleware
from fastapi.security import OAuth2PasswordRequestForm
from sqlalchemy.orm import Session
import asyncio
import json

from .database import engine, Base, SessionLocal, get_db
from . import models, schemas, crud, auth
from .lock_manager import lock_manager

# WebSocket Connection Manager to broadcast live machine state to frontend clients
class ConnectionManager:
    def __init__(self):
        self.active_connections: Set[WebSocket] = set()

    async def connect(self, websocket: WebSocket):
        await websocket.accept()
        self.active_connections.add(websocket)

    def disconnect(self, websocket: WebSocket):
        self.active_connections.remove(websocket)

    async def broadcast(self, message: dict):
        for connection in list(self.active_connections):
            try:
                await connection.send_json(message)
            except Exception:
                # Connection might have closed
                self.active_connections.remove(connection)

ws_manager = ConnectionManager()

# Application Lifespan (Startup / Shutdown)
@asynccontextmanager
async def lifespan(app: FastAPI):
    # 1. Automatical database schema creation (No migrations needed for Phase 1)
    Base.metadata.create_all(bind=engine)
    
    # 2. Reset machine state / recover lock manager
    db = SessionLocal()
    try:
        lock_manager.reset_on_startup(db)
    finally:
        db.close()
    
    yield
    # Shutdown tasks (none required currently)

app = FastAPI(
    title="Dip Coater Control System API",
    description="Backend API for controlling the Dip Coater and managing recipes & jobs.",
    version="1.0.0",
    lifespan=lifespan
)

# CORS configuration
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],  # Adjust for production
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# --- TELEMETRY BROADCASTER BACKGROUND TASK ---
# In a real setup, this would poll the hardware or receive updates.
# For now, we broadcast the lock state every second so the frontend is aware.
async def telemetry_loop():
    while True:
        try:
            holder = lock_manager.get_lock_holder()
            status_report = {
                "type": "telemetry",
                "machine_locked": holder is not None,
                "lock_holder": holder,
                "timestamp": models.datetime.utcnow().isoformat()
            }
            await ws_manager.broadcast(status_report)
        except Exception as e:
            print(f"Error in telemetry loop: {e}")
        await asyncio.sleep(1)

@app.on_event("startup")
async def start_telemetry_loop():
    asyncio.create_task(telemetry_loop())


# ==========================================
# 1. AUTHENTICATION ENDPOINTS
# ==========================================

@app.post("/api/auth/register", response_model=schemas.UserOut, status_code=status.HTTP_201_CREATED)
def register(user_in: schemas.UserCreate, db: Session = Depends(get_db)):
    db_user = crud.get_user_by_username(db, username=user_in.username)
    if db_user:
        raise HTTPException(
            status_code=status.HTTP_400_BAD_REQUEST,
            detail="Username already registered"
        )
    return crud.create_user(db=db, user=user_in)

@app.post("/api/auth/login", response_model=schemas.Token)
def login(form_data: OAuth2PasswordRequestForm = Depends(), db: Session = Depends(get_db)):
    user = crud.get_user_by_username(db, username=form_data.username)
    if not user or not auth.verify_password(form_data.password, user.hashed_password):
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail="Incorrect username or password",
            headers={"WWW-Authenticate": "Bearer"},
        )
    access_token = auth.create_access_token(data={"sub": user.username, "role": user.role})
    return {"access_token": access_token, "token_type": "bearer"}

@app.get("/api/auth/me", response_model=schemas.UserOut)
def read_users_me(current_user: models.User = Depends(auth.get_current_user)):
    return current_user


# ==========================================
# 2. RECIPE CRUD ENDPOINTS
# ==========================================

@app.get("/api/recipes", response_model=List[schemas.RecipeOut])
def list_recipes(skip: int = 0, limit: int = 100, db: Session = Depends(get_db), current_user: models.User = Depends(auth.require_operator)):
    return crud.get_recipes(db, skip=skip, limit=limit)

@app.get("/api/recipes/{recipe_id}", response_model=schemas.RecipeOut)
def read_recipe(recipe_id: int, db: Session = Depends(get_db), current_user: models.User = Depends(auth.require_operator)):
    recipe = crud.get_recipe(db, recipe_id=recipe_id)
    if not recipe:
        raise HTTPException(status_code=404, detail="Recipe not found")
    return recipe

@app.post("/api/recipes", response_model=schemas.RecipeOut, status_code=status.HTTP_201_CREATED)
def create_new_recipe(recipe_in: schemas.RecipeCreate, db: Session = Depends(get_db), current_user: models.User = Depends(auth.require_admin)):
    # Note: require_admin guarantees that only users with the admin role can write recipes.
    return crud.create_recipe(db=db, recipe=recipe_in)

@app.put("/api/recipes/{recipe_id}", response_model=schemas.RecipeOut)
def update_existing_recipe(recipe_id: int, recipe_in: schemas.RecipeCreate, db: Session = Depends(get_db), current_user: models.User = Depends(auth.require_admin)):
    updated_recipe = crud.update_recipe(db=db, recipe_id=recipe_id, recipe=recipe_in)
    if not updated_recipe:
        raise HTTPException(status_code=404, detail="Recipe not found")
    return updated_recipe

@app.delete("/api/recipes/{recipe_id}", status_code=status.HTTP_204_NO_CONTENT)
def delete_existing_recipe(recipe_id: int, db: Session = Depends(get_db), current_user: models.User = Depends(auth.require_admin)):
    success = crud.delete_recipe(db=db, recipe_id=recipe_id)
    if not success:
        raise HTTPException(status_code=404, detail="Recipe not found")
    return None


# ==========================================
# 3. JOB SCHEDULING & MACHINE LOCKS
# ==========================================

@app.get("/api/jobs", response_model=List[schemas.JobOut])
def list_jobs(skip: int = 0, limit: int = 100, db: Session = Depends(get_db), current_user: models.User = Depends(auth.require_operator)):
    return crud.get_jobs(db, skip=skip, limit=limit)

@app.post("/api/jobs", response_model=schemas.JobOut, status_code=status.HTTP_201_CREATED)
def create_job_order(job_in: schemas.JobCreate, db: Session = Depends(get_db), current_user: models.User = Depends(auth.require_operator)):
    recipe = crud.get_recipe(db, recipe_id=job_in.recipe_id)
    if not recipe:
        raise HTTPException(status_code=404, detail="Selected recipe does not exist")
    return crud.create_job(db=db, job=job_in, user_id=current_user.id)

@app.post("/api/jobs/{job_id}/run")
def trigger_job_run(job_id: int, db: Session = Depends(get_db), current_user: models.User = Depends(auth.require_operator)):
    job = crud.get_job(db, job_id=job_id)
    if not job:
        raise HTTPException(status_code=404, detail="Job not found")
    
    if job.status != "queued":
        raise HTTPException(
            status_code=status.HTTP_400_BAD_REQUEST,
            detail=f"Only queued jobs can be started. Current status is: {job.status}"
        )

    # Attempt to acquire exclusive machine control
    acquired = lock_manager.acquire_lock(db=db, user_id=current_user.id, job_id=job_id)
    if not acquired:
        holder = lock_manager.get_lock_holder()
        raise HTTPException(
            status_code=status.HTTP_409_CONFLICT,
            detail=f"Machine is busy. Locked by Job {holder.get('job_id')} under User {holder.get('user_id')}."
        )

    # In Phase 3, this is where we will trigger the asynchronous background Job Execution Engine.
    # For Phase 1, we simulate acquiring the lock and immediately transitioning.
    return {
        "status": "success",
        "message": f"Lock acquired successfully. Job {job_id} is now running.",
        "lock_details": lock_manager.get_lock_holder()
    }

@app.post("/api/jobs/{job_id}/stop")
def stop_job_run(job_id: int, db: Session = Depends(get_db), current_user: models.User = Depends(auth.require_operator)):
    job = crud.get_job(db, job_id=job_id)
    if not job:
        raise HTTPException(status_code=404, detail="Job not found")

    holder = lock_manager.get_lock_holder()
    if not holder or holder.get("job_id") != job_id:
        raise HTTPException(
            status_code=status.HTTP_400_BAD_REQUEST,
            detail="This job is not currently holding the lock or running."
        )

    # Release the lock, marking job status as error
    lock_manager.release_lock(db=db, job_id=job_id, final_status="error")
    return {"status": "success", "message": f"Job {job_id} has been stopped and lock released."}

@app.get("/api/jobs/{job_id}/logs", response_model=List[schemas.RunLogOut])
def get_job_execution_logs(job_id: int, db: Session = Depends(get_db), current_user: models.User = Depends(auth.require_operator)):
    job = crud.get_job(db, job_id=job_id)
    if not job:
        raise HTTPException(status_code=404, detail="Job not found")
    return crud.get_run_logs(db, job_id=job_id)


# ==========================================
# 4. GENERAL MACHINE INTERACTION
# ==========================================

@app.get("/api/machine/status")
def get_machine_general_status():
    holder = lock_manager.get_lock_holder()
    return {
        "machine_locked": holder is not None,
        "lock_holder": holder
    }

@app.post("/api/machine/stop")
def emergency_stop_machine(db: Session = Depends(get_db), current_user: models.User = Depends(auth.require_operator)):
    """
    Emergency Stop releases the lock immediately, forcing the active job to go into error state.
    """
    holder = lock_manager.get_lock_holder()
    if not holder:
        return {"status": "success", "message": "Machine was already idle. E-stop triggered without job disruption."}

    job_id = holder["job_id"]
    lock_manager.release_lock(db=db, job_id=job_id, final_status="error")
    return {
        "status": "success", 
        "message": f"E-stop triggered. Job {job_id} halted. Lock released."
    }


# ==========================================
# 5. WEBSOCKET REAL-TIME BROADCASTS
# ==========================================

@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await ws_manager.connect(websocket)
    try:
        # Send initial status
        holder = lock_manager.get_lock_holder()
        await websocket.send_json({
            "type": "welcome",
            "machine_locked": holder is not None,
            "lock_holder": holder
        })
        
        while True:
            # Keep connection alive; accept messages if necessary
            data = await websocket.receive_text()
            # Respond to ping or other basic control messages if needed
            await websocket.send_json({"type": "pong", "received": data})
    except WebSocketDisconnect:
        ws_manager.disconnect(websocket)
    except Exception:
        ws_manager.disconnect(websocket)
