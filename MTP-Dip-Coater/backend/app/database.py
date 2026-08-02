import os
from sqlalchemy import create_engine
from sqlalchemy.orm import declarative_base, sessionmaker

DATABASE_URL = os.getenv("DATABASE_URL", "postgresql://postgres:password123@db:5432/dip_coater")

# Create engine. In production, Postgres is used. 
# We disable pool_pre_ping to ensure connection health checks are executed.
engine = create_engine(DATABASE_URL, pool_pre_ping=True)

SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)

Base = declarative_base()

# Dependency to get database session per request
def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()
