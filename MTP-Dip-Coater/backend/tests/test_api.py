import pytest
from app.lock_manager import lock_manager

def test_user_registration_and_login(client):
    # 1. Register operator user
    response = client.post(
        "/api/auth/register",
        json={"username": "operator1", "password": "password123", "role": "operator"},
    )
    assert response.status_code == 201
    data = response.json()
    assert data["username"] == "operator1"
    assert data["role"] == "operator"
    assert "id" in data

    # 2. Login
    response = client.post(
        "/api/auth/login",
        data={"username": "operator1", "password": "password123"},
    )
    assert response.status_code == 200
    token_data = response.json()
    assert token_data["token_type"] == "bearer"
    assert "access_token" in token_data

    # 3. Read current user details
    headers = {"Authorization": f"Bearer {token_data['access_token']}"}
    response = client.get("/api/auth/me", headers=headers)
    assert response.status_code == 200
    me_data = response.json()
    assert me_data["username"] == "operator1"
    assert me_data["role"] == "operator"


def test_recipe_permissions(client):
    # Register an admin and an operator
    client.post(
        "/api/auth/register",
        json={"username": "admin1", "password": "password123", "role": "admin"},
    )
    client.post(
        "/api/auth/register",
        json={"username": "op1", "password": "password123", "role": "operator"},
    )

    # Login admin
    admin_token = client.post(
        "/api/auth/login",
        data={"username": "admin1", "password": "password123"},
    ).json()["access_token"]
    admin_headers = {"Authorization": f"Bearer {admin_token}"}

    # Login operator
    op_token = client.post(
        "/api/auth/login",
        data={"username": "op1", "password": "password123"},
    ).json()["access_token"]
    op_headers = {"Authorization": f"Bearer {op_token}"}

    # 1. Operator attempts to create a recipe (Should be Forbidden 403)
    recipe_data = {
        "name": "Gold Nanoparticle Dip",
        "cycles": 3,
        "steps": [
            {
                "beaker_id": 1,
                "dip_depth_mm": 30.5,
                "speed_in_mms": 2.0,
                "speed_out_mms": 4.0,
                "dwell_time_ms": 15000,
            }
        ],
    }
    response = client.post("/api/recipes", json=recipe_data, headers=op_headers)
    assert response.status_code == 403

    # 2. Admin creates a recipe (Should succeed 201)
    response = client.post("/api/recipes", json=recipe_data, headers=admin_headers)
    assert response.status_code == 201
    created_recipe = response.json()
    assert created_recipe["name"] == "Gold Nanoparticle Dip"
    assert created_recipe["id"] is not None
    assert len(created_recipe["steps"]) == 1
    assert created_recipe["steps"][0]["dwell_time_ms"] == 15000


def test_job_flow_and_lock_contention(client):
    # Setup users
    client.post(
        "/api/auth/register",
        json={"username": "admin1", "password": "password123", "role": "admin"},
    )
    client.post(
        "/api/auth/register",
        json={"username": "op1", "password": "password123", "role": "operator"},
    )
    client.post(
        "/api/auth/register",
        json={"username": "op2", "password": "password123", "role": "operator"},
    )

    admin_token = client.post(
        "/api/auth/login", data={"username": "admin1", "password": "password123"}
    ).json()["access_token"]
    op1_token = client.post(
        "/api/auth/login", data={"username": "op1", "password": "password123"}
    ).json()["access_token"]
    op2_token = client.post(
        "/api/auth/login", data={"username": "op2", "password": "password123"}
    ).json()["access_token"]

    admin_headers = {"Authorization": f"Bearer {admin_token}"}
    op1_headers = {"Authorization": f"Bearer {op1_token}"}
    op2_headers = {"Authorization": f"Bearer {op2_token}"}

    # 1. Create a recipe
    recipe_data = {
        "name": "TiO2 Coat",
        "cycles": 1,
        "steps": [
            {
                "beaker_id": 1,
                "dip_depth_mm": 45.0,
                "speed_in_mms": 5.0,
                "speed_out_mms": 5.0,
                "dwell_time_ms": 2000,
            }
        ],
    }
    recipe_id = client.post("/api/recipes", json=recipe_data, headers=admin_headers).json()["id"]

    # 2. Create Job 1 (op1) and Job 2 (op2)
    job1_id = client.post("/api/jobs", json={"recipe_id": recipe_id}, headers=op1_headers).json()["id"]
    job2_id = client.post("/api/jobs", json={"recipe_id": recipe_id}, headers=op2_headers).json()["id"]

    # Check status is queued
    response = client.get("/api/jobs", headers=op1_headers)
    assert response.status_code == 200
    jobs = response.json()
    assert any(j["id"] == job1_id and j["status"] == "queued" for j in jobs)

    # 3. Run Job 1 (Acquires Lock)
    response = client.post(f"/api/jobs/{job1_id}/run", headers=op1_headers)
    assert response.status_code == 200
    assert response.json()["status"] == "success"

    # Verify machine is locked
    status_response = client.get("/api/machine/status", headers=op1_headers)
    assert status_response.json()["machine_locked"] is True
    assert status_response.json()["lock_holder"]["job_id"] == job1_id

    # 4. Attempt to run Job 2 (Should fail with 409 Conflict)
    response = client.post(f"/api/jobs/{job2_id}/run", headers=op2_headers)
    assert response.status_code == 409
    assert "busy" in response.json()["detail"]

    # 5. Stop Job 1
    response = client.post(f"/api/jobs/{job1_id}/stop", headers=op1_headers)
    assert response.status_code == 200

    # Verify lock is released and status is error
    status_response = client.get("/api/machine/status", headers=op1_headers)
    assert status_response.json()["machine_locked"] is False

    response = client.get("/api/jobs", headers=op1_headers)
    assert any(j["id"] == job1_id and j["status"] == "error" for j in response.json())

    # 6. Now Run Job 2 (Should succeed since lock was released)
    response = client.post(f"/api/jobs/{job2_id}/run", headers=op2_headers)
    assert response.status_code == 200
    assert response.json()["status"] == "success"
