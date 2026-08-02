from typing import List, Optional
from sqlalchemy.orm import Session
from datetime import datetime
from . import models, schemas
from .auth import get_password_hash

# --- USER CRUD ---

def get_user(db: Session, user_id: int) -> Optional[models.User]:
    return db.query(models.User).filter(models.User.id == user_id).first()

def get_user_by_username(db: Session, username: str) -> Optional[models.User]:
    return db.query(models.User).filter(models.User.username == username).first()

def create_user(db: Session, user: schemas.UserCreate) -> models.User:
    hashed_pwd = get_password_hash(user.password)
    db_user = models.User(
        username=user.username,
        hashed_password=hashed_pwd,
        role=user.role
    )
    db.add(db_user)
    db.commit()
    db.refresh(db_user)
    return db_user


# --- RECIPE CRUD ---

def get_recipe(db: Session, recipe_id: int) -> Optional[models.Recipe]:
    return db.query(models.Recipe).filter(models.Recipe.id == recipe_id).first()

def get_recipes(db: Session, skip: int = 0, limit: int = 100) -> List[models.Recipe]:
    return db.query(models.Recipe).offset(skip).limit(limit).all()

def create_recipe(db: Session, recipe: schemas.RecipeCreate) -> models.Recipe:
    # Serialize steps to dict lists
    serialized_steps = [step.dict() for step in recipe.steps]
    db_recipe = models.Recipe(
        name=recipe.name,
        cycles=recipe.cycles,
        steps=serialized_steps
    )
    db.add(db_recipe)
    db.commit()
    db.refresh(db_recipe)
    return db_recipe

def update_recipe(db: Session, recipe_id: int, recipe: schemas.RecipeCreate) -> Optional[models.Recipe]:
    db_recipe = get_recipe(db, recipe_id)
    if not db_recipe:
        return None
    db_recipe.name = recipe.name
    db_recipe.cycles = recipe.cycles
    db_recipe.steps = [step.dict() for step in recipe.steps]
    db.commit()
    db.refresh(db_recipe)
    return db_recipe

def delete_recipe(db: Session, recipe_id: int) -> bool:
    db_recipe = get_recipe(db, recipe_id)
    if not db_recipe:
        return False
    db.delete(db_recipe)
    db.commit()
    return True


# --- JOB CRUD ---

def get_job(db: Session, job_id: int) -> Optional[models.Job]:
    return db.query(models.Job).filter(models.Job.id == job_id).first()

def get_jobs(db: Session, skip: int = 0, limit: int = 100) -> List[models.Job]:
    return db.query(models.Job).order_by(models.Job.created_at.desc()).offset(skip).limit(limit).all()

def create_job(db: Session, job: schemas.JobCreate, user_id: int) -> models.Job:
    db_job = models.Job(
        recipe_id=job.recipe_id,
        user_id=user_id,
        status="queued"
    )
    db.add(db_job)
    db.commit()
    db.refresh(db_job)
    return db_job

def update_job_status(db: Session, job_id: int, status: str) -> Optional[models.Job]:
    db_job = get_job(db, job_id)
    if not db_job:
        return None
    db_job.status = status
    if status == "running" and not db_job.started_at:
        db_job.started_at = datetime.utcnow()
    elif status in ("done", "error") and not db_job.finished_at:
        db_job.finished_at = datetime.utcnow()
    db.commit()
    db.refresh(db_job)
    return db_job

def get_active_job(db: Session) -> Optional[models.Job]:
    # Returns the currently running job, if any
    return db.query(models.Job).filter(models.Job.status == "running").first()


# --- RUN LOG CRUD ---

def create_run_log(db: Session, log: schemas.RunLogCreate, job_id: int) -> models.RunLog:
    db_log = models.RunLog(
        job_id=job_id,
        position_x=log.position_x,
        position_y=log.position_y,
        event=log.event
    )
    db.add(db_log)
    db.commit()
    db.refresh(db_log)
    return db_log

def get_run_logs(db: Session, job_id: int) -> List[models.RunLog]:
    return db.query(models.RunLog).filter(models.RunLog.job_id == job_id).order_by(models.RunLog.timestamp.asc()).all()
