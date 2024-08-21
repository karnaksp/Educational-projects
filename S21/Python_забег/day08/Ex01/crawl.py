import asyncio
import httpx
import sys
import time

SERVER_URL = "http://localhost:8888/api/v1/tasks/"
SPINNER = ["|", "/", "-", "\\"]
BLUE = "\033[94m"
RESET = "\033[0m"


async def submit_task(urls):
    async with httpx.AsyncClient() as client:
        response = await client.post(SERVER_URL, json={"urls": urls})
        response.raise_for_status()
        task_data = response.json()
        return task_data["id"]


async def get_task_status(task_id):
    async with httpx.AsyncClient() as client:
        response = await client.get(f"{SERVER_URL}{task_id}")
        response.raise_for_status()
        return response.json()


async def main(urls):
    results = []
    try:
        task_id = await submit_task(urls)
        print(f"Task ID: {task_id}")

        async def spinner_task():
            while True:
                for symbol in SPINNER:
                    sys.stdout.write(
                        f"\r{BLUE}{symbol} Task is still running, waiting...{RESET}"
                    )
                    sys.stdout.flush()
                    await asyncio.sleep(0.1)

        spinner_task_coro = spinner_task()
        spinner_task_task = asyncio.create_task(spinner_task_coro)

        while True:
            task_status = await get_task_status(task_id)
            if task_status["status"] == "ready":
                spinner_task_task.cancel()
                try:
                    await spinner_task_task
                except asyncio.CancelledError:
                    pass
                results = list(zip(task_status["result"], urls))
                break
            else:
                await asyncio.sleep(2)

    except Exception as e:
        print(f"An error occurred: {e}")
    finally:
        sys.stdout.write("\r" + " " * 40 + "\r")
        sys.stdout.flush()
        if results:
            for code, url in results:
                print(f"{code}\t{url}")
        else:
            print("No results were retrieved.")


if __name__ == "__main__":
    urls = sys.argv[1:]
    if not urls:
        print("Usage: python crawl.py <url1> <url2> ...")
        sys.exit(1)

    asyncio.run(main(urls))
