import os
import psycopg
from psycopg.rows import dict_row
from dotenv import load_dotenv
from typing import List, Optional
from contextlib import asynccontextmanager
from fastapi import FastAPI, HTTPException, status, Query
from pydantic import BaseModel, Field
from fastapi.responses import JSONResponse

# Load environment variables
load_dotenv()
DATABASE_URL = os.getenv("DATABASE_URL")



DB_FILE = "tasks.db"

# ------------------------------------------------------------------------------
# Stage 0 : Create You database and initial data
# ------------------------------------------------------------------------------
def init_db():
    # Establish connection to Postgres (using default tuple row factory for init_db)
    with psycopg.connect(DATABASE_URL) as conn:
        with conn.cursor() as cursor:
            # Create the tasks table if it does not exist
            cursor.execute("""
                CREATE TABLE IF NOT EXISTS tasks (
                    id SERIAL PRIMARY KEY,
                    title TEXT NOT NULL,
                    done BOOLEAN DEFAULT FALSE
                )
            """)
            conn.commit()
            
            # Check if the table is empty to decide on seeding
            cursor.execute("SELECT COUNT(*) FROM tasks")
            count = cursor.fetchone()[0]
            if count == 0:
                initial_tasks = [
                    ("SetUp developement environment", True),
                    ("Build FastAPI endpoints", False),
                    ("Test With Swagger UI", False)
                ]
                cursor.executemany(
                    "INSERT INTO tasks (title, done) VALUES (%s, %s)",
                    initial_tasks
                )
                conn.commit()

def get_db_connection():
    # Connect with dict_row to map columns to keys automatically (like sqlite3.Row)
    return psycopg.connect(DATABASE_URL, row_factory=dict_row)


@asynccontextmanager
async def lifespan(app: FastAPI):
    init_db()
    yield

app = FastAPI(
    title="Task API",
    version="1.0",
    description="A complete CRUD API for managing a to-do list built with FastAPI and SQLite.",
    lifespan=lifespan
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
    done: bool

# ------------------------------------------------------------------------------
# Stage 1: Root and Health Endpoints
# ------------------------------------------------------------------------------

@app.get("/", summary="Describe API", tags=["General"])
def read_root():
    """Returns basic description and main endpoints of the API."""
    return {
        "name": "Task API",
        "version": "1.0",
        "endpoints": ["/tasks", "/health"]
    }

@app.get("/health", summary="Health Check", tags=["General"])
def health_check():
    """Endpoint used to verify that the server is alive and running."""
    return {"status": "ok"}

# ------------------------------------------------------------------------------
# Stage 2: Read Endpoints
# ------------------------------------------------------------------------------

@app.get("/tasks", response_model=List[Task], summary="List all tasks", tags=["Tasks"])
def get_tasks(
    done: Optional[bool] = Query(None, description="Filter tasks by completion status"),
    search: Optional[str] = Query(None, description="Search tasks containing title keywords")
):
    """Retrieve all tasks with optional filtering by status or title search."""
    conn = get_db_connection()
    cursor = conn.cursor()
    
    query = "SELECT id, title, done FROM tasks WHERE 1=1"
    params = []
    
    if done is not None:
        query += " AND done = %s"
        params.append(done)
        
    if search is not None:
        query += " AND title LIKE %s"
        params.append(f"%{search}%")
        
    cursor.execute(query, params)
    rows = cursor.fetchall()
    conn.close()
    
    tasks = []
    for r in rows:
        tasks.append({
            "id": r["id"],
            "title": r["title"],
            "done": bool(r["done"])
        })
    return tasks


# Stage 1 : Read from the database

@app.get("/tasks/{task_id}", response_model = Task, summary = "Get single task", tags=["Tasks"])
def get_task(task_id: int):
    """Retrieve a single task by its unique ID from the database."""
    conn = get_db_connection()
    cursor = conn.cursor()

    cursor.execute("SELECT id, title, done FROM tasks WHERE id = %s", (task_id,))
    row = cursor.fetchone()
    conn.close()

    if row is None:
        raise HTTPException(
            status_code = status.HTTP_404_NOT_FOUND, detail = "Task Not Found"
        )

    return {
        "id" : row["id"],
        "title": row['title'],
        "done": bool(row["done"])
    }

# Stage 2 : Create New Tasks
@app.post(
    "/tasks",
    response_model = Task,
    summary = "Create a new task",
    tags = ["Tasks"]
)
def create_task(task_input : TaskCreate):
    """Creates a new task in the database. Validates that title is not empty"""
    title_clean = task_input.title.strip()

    if not title_clean:
        raise HTTPException(
            status_code=status.HTTP_400_BAD_REQUEST,
            detail="Task title cannot be empty or whitespace"
        )

    conn = get_db_connection()
    cursor = conn.cursor()

    cursor.execute("INSERT INTO tasks (title, done) VALUES (?, ?)", (title_clean, 0))
    conn.commit()
    new_id = cursor.lastrowid
    conn.close()

    return{
        "id" : new_id,
        "title":title_clean,
        "done": False
    }
    
# Stage 3 : Update and Delete

@app.put("/tasks/{task_id}", response_model=Task, summary="Update a task", tags=["Tasks"])
def update_task(task_id:int, task_update:TaskUpdate):
    """Updates an existing task by ID. Can update title or completion status (or both)."""
    conn = get_db_connection()
    cursor = conn.cursor()

    cursor.execute("SELECT id, title, done FROM tasks WHERE id = ?", (task_id,))
    row = cursor.fetchone()

    if row is None:
        conn.close()
        raise HTTPException(
            status_code = status.HTTP_404_NOT_FOUND,
            detail = "Task not found"
        )

    new_title = row["title"]
    if task_update.title is not None:
        clean_title = task_update.title.strip()
        
        if not clean_title:
            conn.close()
            raise HTTPException(
                status_code = status.HTTP_400_BAD_REQUEST,
                detail = "Task title cannot be empty or whitespace"
            )

        new_title = clean_title

    new_done = bool(row["done"])
    if task_update.done is not None:
        new_done = 1 if task_update.done else 0

    cursor.execute("UPDATE tasks SET title = ?, done = ? WHERE id = ?", 
        (new_title, new_done, task_id)
    )
    conn.commit()
    conn.close()

    return {
        "id" : task_id,
        "title": new_title,
        "done": bool(new_done)
    }
    
@app.delete(
    "/tasks/{task_id}",
    status_code=status.HTTP_204_NO_CONTENT,
    summary="Delete a task",
    tags=["Tasks"]
)
def delete_task(task_id: int):
    """Deletes a task by ID from the database. Returns 204 No Content on success."""
    conn = get_db_connection()
    cursor = conn.cursor()
    # 1. Check if the task exists
    cursor.execute("SELECT id FROM tasks WHERE id = ?", (task_id,))
    row = cursor.fetchone()
    if row is None:
        conn.close()
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail="Task not found"
        )

    cursor.execute("DELETE FROM tasks WHERE id = ?", (task_id,))
    conn.commit()
    conn.close()
    return None
            

    

