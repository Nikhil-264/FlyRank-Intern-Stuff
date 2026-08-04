import os
from contextlib import asynccontextmanager
from dotenv import load_dotenv
from fastapi import FastAPI
from supabase import create_client, Client

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

@app.get("/")
def read_root():
    return {"message": "API is running. Connected to Supabase."}
