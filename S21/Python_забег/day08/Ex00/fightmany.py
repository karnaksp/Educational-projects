import asyncio
from fight import fight


async def fightmany(n: int):
    await asyncio.gather(*(fight(f" {i + 1}", False) for i in range(n)))
    print("Neo wins!")


if __name__ == "__main__":
    asyncio.run(fightmany(5))
