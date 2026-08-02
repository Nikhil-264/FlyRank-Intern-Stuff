from datetime import datetime
from typing import List, Optional
from pydantic import BaseModel, Field, field_validator

# --- USER SCHEMAS ---

class UserBase(BaseModel):
    username: str

class UserCreate(UserBase):
    password: str
    role: str = "operator"  # Must be "admin" or "operator"

    @field_validator("role")
    @classmethod
    def validate_role(cls, v: str) -> str:
        if v not in ("admin", "operator"):
            raise ValueError("role must be either 'admin' or 'operator'")
        return v

class UserOut(UserBase):
    id: int
    role: str

    class Config:
        from_attributes = True


# --- AUTH TOKEN SCHEMAS ---

class Token(BaseModel):
    access_token: str
    token_type: str

class TokenData(BaseModel):
    username: Optional[str] = None
    role: Optional[str] = None


# --- RECIPE SCHEMAS ---

class RecipeStep(BaseModel):
    beaker_id: int = Field(..., description="ID of the beaker to dip into")
    dip_depth_mm: float = Field(..., gt=0.0, description="Dipping depth in mm")
    speed_in_mms: float = Field(..., gt=0.0, description="Dipping speed in mm/s")
    speed_out_mms: float = Field(..., gt=0.0, description="Withdrawal speed in mm/s")
    dwell_time_ms: int = Field(..., ge=0, description="Dwell time in milliseconds")

class RecipeBase(BaseModel):
    name: str
    cycles: int = Field(1, ge=1, description="Number of repeat cycles")
    steps: List[RecipeStep]

class RecipeCreate(RecipeBase):
    pass

class RecipeOut(RecipeBase):
    id: int
    created_at: datetime
    updated_at: datetime

    class Config:
        from_attributes = True


# --- JOB SCHEMAS ---

class JobCreate(BaseModel):
    recipe_id: int

class JobOut(BaseModel):
    id: int
    recipe_id: int
    user_id: int
    status: str  # "idle", "queued", "running", "done", "error"
    started_at: Optional[datetime] = None
    finished_at: Optional[datetime] = None
    created_at: datetime
    recipe: Optional[RecipeOut] = None
    user: Optional[UserOut] = None

    class Config:
        from_attributes = True


# --- RUN LOG SCHEMAS ---

class RunLogCreate(BaseModel):
    position_x: Optional[float] = None
    position_y: Optional[float] = None
    event: str

class RunLogOut(BaseModel):
    id: int
    job_id: int
    timestamp: datetime
    position_x: Optional[float] = None
    position_y: Optional[float] = None
    event: str

    class Config:
        from_attributes = True
