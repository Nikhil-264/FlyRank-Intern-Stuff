FROM python:3.10-slim

WORKDIR /app

# Install backend dependencies
RUN pip install --no-cache-dir fastapi uvicorn "psycopg[binary]" python-dotenv pydantic

# Copy files
COPY . .

# Expose FastAPI's default port
EXPOSE 8000

# Start the server
CMD ["uvicorn", "main:app", "--host", "0.0.0.0", "--port", "8000"]
