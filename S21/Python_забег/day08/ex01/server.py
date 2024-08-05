from fastapi import FastAPI, HTTPException, BackgroundTasks
import pydantic
from aiohttp import ClientSession
import asyncio
from uuid import uuid4


class Task(pydantic.BaseModel):
    id: pydantic.UUID4
    urls: list[pydantic.HttpUrl]
    status: str
    result: list[int | None]

    def __init__(self, id, urls) -> None:
        super().__init__(id=id, urls=urls, status="running", result=[None for i in range(len(urls))])

    async def process(self):
        async with ClientSession(conn_timeout=3) as session:
            await asyncio.gather(*[self.process_url(i, session) for i in range(len(self.urls))])
            self.status = "ready"
    
    async def process_url(self, idx: int, session: ClientSession):
        async with session.get(str(self.urls[idx])) as response:
            self.result[idx] = response.status

class Urls(pydantic.BaseModel):
    urls: list[pydantic.HttpUrl]

app = FastAPI()
tasks = {}

@app.post("/api/v1/tasks", status_code=201)
async def set_up_task(urls: Urls, background_tasks: BackgroundTasks):
    id = uuid4()
    tasks[id] = Task(id, urls.urls)
    background_tasks.add_task(tasks[id].process)
    return tasks[id]

@app.get("/api/v1/tasks/{id}")
async def get_status(id: pydantic.UUID4):
    if id not in tasks:
        raise HTTPException(status_code=404, detail="Don't have task with such id")
    return tasks[id]
        