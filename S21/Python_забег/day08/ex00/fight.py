import asyncio

from enum import Enum, auto
from random import choice, random


class Action(Enum):
    HIGHKICK = auto()
    LOWKICK = auto()
    HIGHBLOCK = auto()
    LOWBLOCK = auto()


class Agent:

    def __aiter__(self, health=5):
        self.health = health
        self.actions = list(Action)
        return self

    async def __anext__(self):
        return choice(self.actions)
    
async def fight(suffix: str = '', print_win: bool = True):
    agent = Agent()
    async for action in agent:
        await asyncio.sleep(random() * 0.2)
        if agent.health > 0:
            neo_action = None
            if action == Action.HIGHBLOCK:
                neo_action = Action.LOWKICK
                agent.health -= 1
            elif action == Action.LOWKICK:
                neo_action = Action.LOWBLOCK
            elif action == Action.HIGHKICK:
                neo_action = Action.HIGHBLOCK
            elif action == Action.LOWBLOCK:
                neo_action = Action.HIGHKICK
                agent.health -= 1
            print(f"Agent{ suffix }: {action}, Neo: {neo_action}, Agent{ suffix } health: {agent.health}")
        else:
            if print_win:
                print("Neo wins!")
            return

async def fightmany(n: int):
    fights = list(fight(f" {i + 1}", False) for i in range(n))
    await asyncio.gather(*fights)
    print("Neo wins!")

if __name__ == "__main__":
    asyncio.run(fightmany(5))