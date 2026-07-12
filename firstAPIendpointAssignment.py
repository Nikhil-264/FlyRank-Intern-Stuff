from fastapi import FastAPI

app = FastAPI()

@app.get("/")
def read_root():
    return {"message": "Hello, welcome to my first API!"}

@app.get("/status")
def read_status():
    return {"status": "success", "data": "Server is running perfectly"}