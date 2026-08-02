import threading
from datetime import datetime
from typing import Optional, Dict
from sqlalchemy.orm import Session
from . import crud, models

class MachineLockManager:
    def __init__(self):
        self._lock = threading.Lock()
        self._active_job_id: Optional[int] = None
        self._active_user_id: Optional[int] = None

    def acquire_lock(self, db: Session, user_id: int, job_id: int) -> bool:
        """
        Attempt to acquire exclusive control of the machine for a specific job.
        Checks both the in-memory state and database state.
        """
        with self._lock:
            # 1. Check in-memory state
            if self._active_job_id is not None:
                return False

            # 2. Check database state to ensure no other job is marked running
            db_active_job = crud.get_active_job(db)
            if db_active_job and db_active_job.id != job_id:
                # Synchronize in-memory state if db has a running job
                self._active_job_id = db_active_job.id
                self._active_user_id = db_active_job.user_id
                return False

            # 3. Acquire lock: update database and memory
            crud.update_job_status(db, job_id, "running")
            self._active_job_id = job_id
            self._active_user_id = user_id
            
            # Log the event
            crud.create_run_log(
                db, 
                log=models.RunLog(event="LOCK_ACQUIRED", position_x=0.0, position_y=0.0), 
                job_id=job_id
            )
            return True

    def release_lock(self, db: Session, job_id: int, final_status: str = "done") -> bool:
        """
        Release control of the machine.
        """
        if final_status not in ("done", "error"):
            raise ValueError("final_status must be 'done' or 'error'")

        with self._lock:
            # Check if this job actually holds the lock
            # If memory state is empty, check db state
            if self._active_job_id is not None and self._active_job_id != job_id:
                return False

            # Update database status
            crud.update_job_status(db, job_id, final_status)
            
            # Log the release
            crud.create_run_log(
                db, 
                log=models.RunLog(event=f"LOCK_RELEASED_{final_status.upper()}", position_x=0.0, position_y=0.0), 
                job_id=job_id
            )

            # Reset memory state
            self._active_job_id = None
            self._active_user_id = None
            return True

    def force_release(self, db: Session) -> None:
        """
        Force-release the lock. Used for emergency stops or manual overrides.
        """
        with self._lock:
            if self._active_job_id is not None:
                crud.update_job_status(db, self._active_job_id, "error")
                self._active_job_id = None
                self._active_user_id = None

    def get_lock_holder(self) -> Optional[Dict[str, int]]:
        """
        Returns details of the current lock holder, if any.
        """
        with self._lock:
            if self._active_job_id is None:
                return None
            return {
                "job_id": self._active_job_id,
                "user_id": self._active_user_id
            }

    def reset_on_startup(self, db: Session) -> None:
        """
        Recovers from unexpected server shutdowns. Any job left in 'running' state
        is marked as 'error'.
        """
        with self._lock:
            running_jobs = db.query(models.Job).filter(models.Job.status == "running").all()
            for job in running_jobs:
                job.status = "error"
                job.finished_at = db.query(models.Job).filter(models.Job.id == job.id).first().finished_at or datetime.utcnow()
                # Log interruption
                db_log = models.RunLog(
                    job_id=job.id,
                    event="SYSTEM_RESET_INTERRUPTED",
                    position_x=0.0,
                    position_y=0.0
                )
                db.add(db_log)
            db.commit()
            
            # Clear memory
            self._active_job_id = None
            self._active_user_id = None

# Global instance of lock manager
lock_manager = MachineLockManager()
