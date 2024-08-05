import aiohttp
import argparse
from json import loads
import asyncio

async def main(urls: list[str]):
    async with aiohttp.ClientSession() as session:
        # ["https://google.com" for i in range(50)]
        async with session.post("http://127.0.0.1:8888/api/v1/tasks", json={"urls": urls}) as responce:
            if responce.status != 201:
                raise Exception(await responce.text())
            data = loads(await responce.text())
            id = data["id"]
            readiness = 0
        while True:
            async with session.get(f"http://127.0.0.1:8888/api/v1/tasks/{id}") as responce:
                data = loads(await responce.text())

            if readiness != sum([1 if i else 0 for i in data['result']]) / len(data['result']):
                readiness = sum([1 if i else 0 for i in data['result']]) / len(data['result'])
                print(f"Request status: {round(readiness * 100)}%")
            if data["status"] == "ready":
                break 
            await asyncio.sleep(0.2)
    
    print('\n'.join([f"{data['result'][i]}  {data['urls'][i]}" for i in range(len(data["urls"]))]))
            


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("urls")
    args = parser.parse_args()

    asyncio.run(main(args.urls.split(",")))
