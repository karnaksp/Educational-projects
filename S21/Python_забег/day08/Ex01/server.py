import uuid
import asyncio
import logging
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
from typing import List, Dict, Optional
import httpx

app = FastAPI()
logging.basicConfig(level=logging.INFO)

tasks: Dict[str, Dict] = {}


class TaskRequest(BaseModel):
    urls: List[str]


class TaskResponse(BaseModel):
    id: str
    status: str
    result: Optional[List[Optional[int]]] = None


@app.post("/api/v1/tasks/", response_model=TaskResponse, status_code=201)
async def create_task(task_request: TaskRequest):
    task_id = str(uuid.uuid4())
    tasks[task_id] = {"status": "running", "result": None}
    logging.info(f"Created task {task_id} with URLs: {task_request.urls}")
    asyncio.create_task(process_task(task_id, task_request.urls))
    return {"id": task_id, "status": "running"}


@app.get("/api/v1/tasks/{task_id}", response_model=TaskResponse)
async def get_task_status(task_id: str):
    task = tasks.get(task_id)
    if not task:
        raise HTTPException(status_code=404, detail="Task not found")
    return {"id": task_id, "status": task["status"], "result": task.get("result")}


async def process_task(task_id: str, urls: List[str]):
    results = []
    async with httpx.AsyncClient() as client:
        for url in urls:
            try:
                response = await client.get(url)
                results.append(response.status_code)
                logging.info(f"URL {url} returned status code {response.status_code}")
            except httpx.HTTPStatusError as e:
                results.append(e.response.status_code)
                logging.error(f"HTTP error for {url}: {e}")
            except httpx.RequestError as e:
                results.append(503)
                logging.error(f"Request error for {url}: {e}")
            except Exception as e:
                results.append(500)
                logging.error(f"Unhandled exception for {url}: {e}")

    tasks[task_id]["status"] = "ready"
    tasks[task_id]["result"] = results
    logging.info(f"Task {task_id} completed with results: {results}")


if __name__ == "__main__":
    import uvicorn

    uvicorn.run(app, host="localhost", port=8888)
