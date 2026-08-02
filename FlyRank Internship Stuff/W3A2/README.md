# Task CRUD API with Containerized PostgreSQL Backend

This is a database-backed REST API for managing a to-do list built with FastAPI, PostgreSQL, and Docker. 

Swapping SQLite for a real PostgreSQL database allows for a professional production-grade storage system where data persists securely in a Docker volume.

## Quick Start (Run with One Command)

To start the database and the web application together, simply run:
```bash
docker compose up
```

Before running the command, ensure you create a `.env` file containing your connection string. You can use `.env.example` as a template:
```bash
cp .env.example .env
```

---

## Configuration & Environment Secrets
Credentials and ports are managed outside the codebase via a git-ignored `.env` file:
* **`.env`** (ignored): Contains the active connection string:
  ```env
  DATABASE_URL=postgresql://postgres:dev@localhost:5433/tasks?connect_timeout=3
  ```
* **`.env.example`** (committed): Template for public setup:
  ```env
  DATABASE_URL=postgresql://postgres:dev@localhost:5432/tasks
  ```

---

## API Endpoints Reference

| Method | Endpoint | Description | Request Body | Success Status |
| :--- | :--- | :--- | :--- | :--- |
| **GET** | `/` | Describe API name, version, and main endpoints | None | `200 OK` |
| **GET** | `/health` | Verify server is alive and running | None | `200 OK` |
| **GET** | `/tasks` | List all tasks (supports query filtering: `done` and `search`) | None | `200 OK` |
| **GET** | `/tasks/{id}` | Retrieve a single task by ID | None | `200 OK` |
| **POST** | `/tasks` | Create a new task (validates non-empty title) | `{"title": "string"}` | `201 Created` |
| **PUT** | `/tasks/{id}` | Update task title and/or completion status | `{"title": "string", "done": bool}` | `200 OK` |
| **DELETE**| `/tasks/{id}` | Delete a task by ID | None | `204 No Content` |

---

## Verification & Output Example

Here is a sample response of retrieving the tasks using `curl -i`:

```http
HTTP/1.1 200 OK
date: Sun, 02 Aug 2026 12:00:00 GMT
server: uvicorn
content-length: 227
content-type: application/json

[
  {
    "id": 1,
    "title": "SetUp developement environment",
    "done": true
  },
  {
    "id": 2,
    "title": "Build FastAPI endpoints",
    "done": false
  },
  {
    "id": 3,
    "title": "Test With Swagger UI",
    "done": false
  }
]
```

---

## Database Screenshot
Here is the current snapshot of the tasks inside the PostgreSQL database inside Docker:

![Screenshot of the query output](image.png)