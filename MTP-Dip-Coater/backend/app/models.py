from datetime import datetime
from sqlalchemy import Column, Integer, String, Float, DateTime, ForeignKey, JSON
from sqlalchemy.orm import relationship
from .database import Base

class User(Base):
    __tablename__ = "users"

    id = Column(Integer, primary_key=True, index=True)
    username = Column(String, unique=True, index=True, nullable=False)
    hashed_password = Column(String, nullable=False)
    role = Column(String, default="operator", nullable=False)  # "admin" or "operator"

    # Relationships
    jobs = relationship("Job", back_populates="user")


class Recipe(Base):
    __tablename__ = "recipes"

    id = Column(Integer, primary_key=True, index=True)
    name = Column(String, index=True, nullable=False)
    cycles = Column(Integer, default=1, nullable=False)
    
    # Store steps as a JSON list. E.g.:
    # [
    #   {"beaker_id": 1, "dip_depth_mm": 50.0, "speed_in_mms": 5.0, "speed_out_mms": 5.0, "dwell_time_ms": 10000},
    #   {"beaker_id": 2, "dip_depth_mm": 40.0, "speed_in_mms": 2.5, "speed_out_mms": 2.5, "dwell_time_ms": 5000}
    # ]
    steps = Column(JSON, nullable=False, default=list)
    
    created_at = Column(DateTime, default=datetime.utcnow, nullable=False)
    updated_at = Column(DateTime, default=datetime.utcnow, onupdate=datetime.utcnow, nullable=False)

    # Relationships
    jobs = relationship("Job", back_populates="recipe")


class Job(Base):
    __tablename__ = "jobs"

    id = Column(Integer, primary_key=True, index=True)
    recipe_id = Column(Integer, ForeignKey("recipes.id"), nullable=False)
    user_id = Column(Integer, ForeignKey("users.id"), nullable=False)
    
    # status can be: "idle", "queued", "running", "done", "error"
    status = Column(String, default="queued", index=True, nullable=False)
    
    started_at = Column(DateTime, nullable=True)
    finished_at = Column(DateTime, nullable=True)
    
    created_at = Column(DateTime, default=datetime.utcnow, nullable=False)

    # Relationships
    recipe = relationship("Recipe", back_populates="jobs")
    user = relationship("User", back_populates="jobs")
    run_logs = relationship("RunLog", back_populates="job", cascade="all, delete-orphan")


class RunLog(Base):
    __tablename__ = "run_logs"

    id = Column(Integer, primary_key=True, index=True)
    job_id = Column(Integer, ForeignKey("jobs.id", ondelete="CASCADE"), nullable=False)
    
    timestamp = Column(DateTime, default=datetime.utcnow, index=True, nullable=False)
    position_x = Column(Float, nullable=True)
    position_y = Column(Float, nullable=True)
    event = Column(String, nullable=False)  # e.g., "START", "MOVE_START", "MOVE_DONE", "DWELL", "STOP", "ERROR"

    # Relationships
    job = relationship("Job", back_populates="run_logs")
