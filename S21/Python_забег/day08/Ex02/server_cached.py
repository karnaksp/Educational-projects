from fastapi import FastAPI, HTTPException
from pydantic import BaseModel
import redis.asyncio as redis
import httpx
import asyncio
from urllib.parse import urlparse
from typing import List, Dict, Optional
import uuid
import logging

app = FastAPI()
logging.basicConfig(level=logging.INFO)
redis_client = redis.from_url("redis://localhost:6379")


class TaskRequest(BaseModel):
    urls: List[str]


class TaskResponse(BaseModel):
    id: str
    status: str
    result: Optional[List[Optional[int]]] = None


@app.post("/api/v1/tasks/", response_model=TaskResponse)
async def create_task(task: TaskRequest):
    task_id = str(uuid.uuid4())
    await redis_client.hset(f"task:{task_id}", "status", "running")
    await redis_client.hset(f"task:{task_id}", "result", "")
    urls = task.urls
    asyncio.create_task(process_urls(task_id, urls))
    return TaskResponse(id=task_id, status="running", result=[])


@app.get("/api/v1/tasks/{task_id}", response_model=TaskResponse)
async def get_task_status(task_id: str):
    task_data = await redis_client.hgetall(f"task:{task_id}")
    if not task_data:
        raise HTTPException(status_code=404, detail="Task not found")
    status = task_data.get(b"status", b"").decode()
    result = task_data.get(b"result", b"").decode()
    if status == "ready":
        result = result.split(",") if result else []
        result = [int(code) for code in result]
    return TaskResponse(id=task_id, status=status, result=result)


async def process_urls(task_id: str, urls: List[str]):
    results = []
    domain_counter = {}

    for url in urls:
        parsed_url = urlparse(url)
        domain = parsed_url.netloc
        cached_code = await redis_client.get(f"cache:{url}")
        if cached_code:
            logging.info(f"Cache hit for {url}: {cached_code.decode()}")
            results.append(int(cached_code))
        else:
            logging.info(f"Cache miss for {url}. Fetching...")
            async with httpx.AsyncClient() as client:
                try:
                    response = await client.get(url)
                    code = response.status_code
                except httpx.HTTPStatusError as e:
                    code = e.response.status_code
                    logging.error(f"HTTP error for {url}: {e}")
                except httpx.RequestError as e:
                    code = 503
                    logging.error(f"Request error for {url}: {e}")
                except Exception as e:
                    code = 500
                    logging.error(f"Unhandled exception for {url}: {e}")
                await redis_client.set(f"cache:{url}", code, ex=3600)
                results.append(code)
                logging.info(f"Cached {url} with code {code}")

        domain_counter[domain] = domain_counter.get(domain, 0) + 1
    await redis_client.hset(f"task:{task_id}", "status", "ready")
    await redis_client.hset(f"task:{task_id}", "result", ",".join(map(str, results)))
    for domain, count in domain_counter.items():
        await redis_client.hincrby(f"domain_count", domain, count)


async def cleanup_cache(timeout: int):
    while True:
        await asyncio.sleep(timeout)
        keys = await redis_client.keys("cache:*")
        for key in keys:
            ttl = await redis_client.ttl(key)
            if ttl == -1:
                await redis_client.delete(key)


if __name__ == "__main__":
    import uvicorn

    uvicorn.run("server_cached:app", host="0.0.0.0", port=8888, reload=True)
