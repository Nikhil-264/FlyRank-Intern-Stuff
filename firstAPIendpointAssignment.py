from typing import List, Optional
from fastapi import FastAPI, HTTPException, status, Query
from pydantic import BaseModel, Field

app = FastAPI(
    title="Task API",
    version="1.0",
    description="A complete CRUD API for managing a to-do list built with FastAPI."
)

# ------------------------------------------------------------------------------
# Data Models & Schemas
# ------------------------------------------------------------------------------

class TaskBase(BaseModel):
    title: str = Field(..., min_length=1, description="Title of the task (cannot be empty)")

class TaskCreate(TaskBase):
    pass

class TaskUpdate(BaseModel):
    title: Optional[str] = Field(None, min_length=1, description="Updated title of the task")
    done: Optional[bool] = Field(None, description="Completion status of the task")

class Task(TaskBase):
    id: int
    done: bool = False

# ------------------------------------------------------------------------------
# In-Memory Storage & Pre-filled Data
# ------------------------------------------------------------------------------

tasks_db: List[dict] = [
    {"id": 1, "title": "Setup development environment", "done": True},
    {"id": 2, "title": "Build FastAPI endpoints", "done": False},
    {"id": 3, "title": "Test with Swagger UI", "done": False},
]

def get_next_id() -> int:
    """Helper function to calculate the next incremental ID."""
    return max([task["id"] for task in tasks_db], default=0) + 1


# ------------------------------------------------------------------------------
# Stage 1: Root and Health Endpoints
# ------------------------------------------------------------------------------

@app.get("/", summary="Describe API", tags=["General"])
def read_root():
    """Returns basic description and main endpoints of the API."""
    return {
        "name": "Task API",
        "version": "1.0",
        "endpoints": ["/tasks", "/health", "/stats"]
    }

@app.get("/health", summary="Health Check", tags=["General"])
def health_check():
    """Endpoint used to verify that the server is alive and running."""
    return {"status": "ok"}


# ------------------------------------------------------------------------------
# Stage 2: Read Endpoints (With Search & Filter Extras)
# ------------------------------------------------------------------------------

@app.get("/tasks", response_model=List[Task], summary="List all tasks", tags=["Tasks"])
def get_tasks(
    done: Optional[bool] = Query(None, description="Filter tasks by completion status"),
    search: Optional[str] = Query(None, description="Search tasks containing title keywords")
):
    """Retrieve all tasks with optional filtering by status or title search."""
    filtered_tasks = tasks_db

    if done is not None:
        filtered_tasks = [t for t in filtered_tasks if t["done"] == done]

    if search is not None:
        filtered_tasks = [
            t for t in filtered_tasks if search.lower() in t["title"].lower()
        ]

    return filtered_tasks


@app.get("/tasks/{task_id}", response_model=Task, summary="Get single task", tags=["Tasks"])
def get_task(task_id: int):
    """Retrieve a single task by its unique ID."""
    for task in tasks_db:
        if task["id"] == task_id:
            return task
    raise HTTPException(
        status_code=status.HTTP_404_NOT_FOUND,
        detail=f"Task {task_id} not found"
    )


# ------------------------------------------------------------------------------
# Stage 3: Create Endpoint with Input Validation
# ------------------------------------------------------------------------------

@app.post(
    "/tasks",
    response_model=Task,
    status_code=status.HTTP_201_CREATED,
    summary="Create a new task",
    tags=["Tasks"]
)
def create_task(task_input: TaskCreate):
    """Creates a new task. Input title is validated to ensure it is non-empty."""
    title_clean = task_input.title.strip()
    if not title_clean:
        raise HTTPException(
            status_code=status.HTTP_400_BAD_REQUEST,
            detail="Task title cannot be empty or whitespace"
        )

    new_task = {
        "id": get_next_id(),
        "title": title_clean,
        "done": False
    }
    tasks_db.append(new_task)
    return new_task


# ------------------------------------------------------------------------------
# Stage 4: Update & Delete Endpoints
# ------------------------------------------------------------------------------

@app.put("/tasks/{task_id}", response_model=Task, summary="Update a task", tags=["Tasks"])
def update_task(task_id: int, task_update: TaskUpdate):
    """Updates an existing task's title or completion status."""
    task_index = next((index for index, t in enumerate(tasks_db) if t["id"] == task_id), None)

    if task_index is None:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail=f"Task {task_id} not found"
        )

    # Validate non-empty title if title update is provided
    if task_update.title is not None:
        clean_title = task_update.title.strip()
        if not clean_title:
            raise HTTPException(
                status_code=status.HTTP_400_BAD_REQUEST,
                detail="Task title cannot be empty or whitespace"
            )
        tasks_db[task_index]["title"] = clean_title

    if task_update.done is not None:
        tasks_db[task_index]["done"] = task_update.done

    return tasks_db[task_index]


@app.delete(
    "/tasks/{task_id}",
    status_code=status.HTTP_204_NO_CONTENT,
    summary="Delete a task",
    tags=["Tasks"]
)
def delete_task(task_id: int):
    """Deletes a task by ID. Returns 204 No Content on success."""
    task_index = next((index for index, t in enumerate(tasks_db) if t["id"] == task_id), None)

    if task_index is None:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail=f"Task {task_id} not found"
        )

    tasks_db.pop(task_index)
    return None


# ------------------------------------------------------------------------------
# Extra Features (Optional Extras)
# ------------------------------------------------------------------------------

@app.get("/stats", summary="Get task statistics", tags=["Extras"])
def get_stats():
    """Computes basic total, completed, and open counts for tasks."""
    total = len(tasks_db)
    done_count = sum(1 for t in tasks_db if t["done"])
    return {
        "total": total,
        "done": done_count,
        "open": total - done_count
    }


@app.post("/reset", summary="Reset tasks database", tags=["Extras"])
def reset_tasks():
    """Resets the in-memory database back to default initial state."""
    global tasks_db
    tasks_db.clear()
    tasks_db.extend([
        {"id": 1, "title": "Setup development environment", "done": True},
        {"id": 2, "title": "Build FastAPI endpoints", "done": False},
        {"id": 3, "title": "Test with Swagger UI", "done": False},
    ])
    return {"message": "Tasks database reset to default state"}