# Interface Contract: Backend/Relay ↔ Motion Controller

This document establishes the communication contract for controlling the dip coater. During early phases, the backend communicates with a **Mock Device Server** via WebSockets or HTTP. In production (Phase 6), this contract will map to **serial (USB)** commands (e.g., G-code / GRBL) sent via an **Edge Relay**.

## 1. Commands

Commands are sent from the Backend (or Relay) to the controller.

### `HOME`
- **Purpose:** Initiates the homing sequence on X and Y axes to calibrate coordinates against limit switches.
- **Payload:** None (or `{ "command": "HOME" }`)

### `MOVE`
- **Purpose:** Moves the carriage to absolute coordinates (x, y).
- **Parameters:**
  - `x` (float, mm): Target X-coordinate (e.g., align with a specific beaker).
  - `y` (float, mm): Target Y-coordinate (e.g., vertical dipping depth).
  - `speed` (float, mm/s): Maximum feed rate for the move.
  - `accel` (float, mm/s²): Acceleration limit for the move.
- **Payload Example:**
  ```json
  {
    "command": "MOVE",
    "params": {
      "x": 120.0,
      "y": -50.0,
      "speed": 10.0,
      "accel": 100.0
    }
  }
  ```

### `DWELL`
- **Purpose:** Suspends motion and remains at the current position for a specified period (e.g., sample dipping/drying duration).
- **Parameters:**
  - `duration_ms` (int, milliseconds): Time to dwell.
- **Payload Example:**
  ```json
  {
    "command": "DWELL",
    "params": {
      "duration_ms": 5000
    }
  }
  ```

### `STATUS`
- **Purpose:** Queries the current status of the machine.
- **Payload:** None (or `{ "command": "STATUS" }`)

### `STOP`
- **Purpose:** Halts current actions immediately (equivalent to GRBL feed hold or reset command).
- **Payload:** None (or `{ "command": "STOP" }`)

---

## 2. Responses & Status Reports

Responses are returned by the controller following command execution, or pushed periodically (e.g., via WebSockets).

### Status Structure
```json
{
  "state": "idle" | "homing" | "moving" | "dwelling" | "error" | "disconnected",
  "position": {
    "x": 120.0,
    "y": -50.0
  },
  "current_command": "MOVE" | "DWELL" | "HOME" | "NONE",
  "error_code": 0 | 1 | 2,
  "error_message": ""
}
```

### Error Codes
- `0`: Success / No Error.
- `1`: Target out of bounds (soft limit exceeded).
- `2`: Limit switch triggered unexpectedly (hard crash).
- `3`: Command timeout or communication error.
