import os
from contextlib import asynccontextmanager
from typing import Optional
from dotenv import load_dotenv
from fastapi import FastAPI, status, Request
from fastapi.responses import JSONResponse
from fastapi.encoders import jsonable_encoder
from pydantic import BaseModel
from supabase import create_client, Client

try:
    from gotrue.errors import AuthApiError
except ImportError:
    try:
        from supabase import AuthApiError
    except ImportError:
        AuthApiError = Exception

# Load environment variables from .env file
load_dotenv()

supabase_url = os.getenv("SUPABASE_URL")
supabase_key = os.getenv("SUPABASE_KEY")

if not supabase_url or not supabase_key:
    raise ValueError("SUPABASE_URL and SUPABASE_KEY must be set in your .env file")

# Initialize the Supabase client
supabase: Client = create_client(supabase_url, supabase_key)

@asynccontextmanager
async def lifespan(app: FastAPI):
    # Startup checkpoint
    print("Server running and connected to Supabase")
    yield

# Create FastAPI instance with lifespan event
app = FastAPI(
    title="BE-03: Supabase Auth with FastAPI",
    description="Week 4 Assignment A4: Supabase Auth with FastAPI",
    version="1.0.0",
    lifespan=lifespan
)

class UserAuth(BaseModel):
    email: Optional[str] = None
    password: Optional[str] = None

@app.get("/")
def read_root():
    return {"message": "API is running. Connected to Supabase."}


@app.post("/auth/signup")
def signup(user_data:UserAuth):
    # Validate missing fields
    if not user_data.email or not user_data.password or not user_data.email.strip() or not user_data.password.strip():
        return JSONResponse(
            status_code=400,
            content={"error": "Email and password are required"}
        )

    try:
        response = supabase.auth.sign_up({
            "email":user_data.email,
            "password":user_data.password
        })
        # Is signup is successful, return 201 with the user details
        return JSONResponse(
            status_code=201,
            content = jsonable_encoder(response.user)
        )
    except AuthApiError as e:
        return JSONResponse(
            status_code = 500,
            content = {"error" : str(e)}
        )


@app.post("/auth/login")
def login(user_data : UserAuth):
    # Validate missing fields
    if not user_data.email or not user_data.password or not user_data.email.strip() or not user_data.password.strip():
        return JSONResponse(
            status_code=400,
            content={"error" : "Email and password are required"}
        )

    try:
        response = supabase.auth.sign_in_with_password({
            "email" : user_data.email,
            "password" : user_data.password
        })
        return {
            'access_token': response.session.access_token,
            'refresh_token': response.session.refresh_token
        }
    except AuthApiError as e:
        # If supabase rejects credentials return 401
        return JSONResponse(
            status_code = 401,
            content = {"error": "Invalid Login credentials"}
        )
    except Exception as e:
        return JSONResponse(
            status_code = 500,
            content = {"error": str(e)}
        )


@app.get("/public/info")
def public_info():
    return {"message": "Welcome stranger! This info is public."}


@app.get("/protected/profile")
def protected_profile(request: Request):
    auth_header = request.headers.get("Authorization")
    if not auth_header:
        return JSONResponse(
            status_code=401,
            content={"error": "Access token required"}
        )

    parts = auth_header.split(" ")
    if len(parts) != 2 or parts[0].lower() != "bearer" or not parts[1].strip():
        return JSONResponse(
            status_code=401,
            content={"error": "Access token required"}
        )

    token = parts[1].strip()

    try:
        # Verify the token with Supabase
        response = supabase.auth.get_user(token)
        user = response.user

        # Return 200 with the user's safe metadata (id, email, created_at)
        return {
            "id": user.id,
            "email": user.email,
            "created_at": user.created_at
        }
    except AuthApiError as e:
        # Return 401 if token is expired, tampered, or invalid
        return JSONResponse(
            status_code=401,
            content={"error": "Invalid or expired token"}
        )
    except Exception as e:
        return JSONResponse(
            status_code=401,
            content={"error": "Invalid or expired token"}
        )


