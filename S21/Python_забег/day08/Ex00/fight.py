import asyncio
from enum import Enum, auto
from random import choice, random


class Action(Enum):
    HIGHKICK = auto()
    LOWKICK = auto()
    HIGHBLOCK = auto()
    LOWBLOCK = auto()


class Agent:
    def __init__(self, health=5):
        self.health = health
        self.actions = list(Action)

    async def act(self):
        return choice(self.actions)


async def fight(suffix: str = "", print_win: bool = True):
    agent = Agent()
    action_map = {
        Action.HIGHBLOCK: Action.LOWKICK,
        Action.LOWKICK: Action.LOWBLOCK,
        Action.HIGHKICK: Action.HIGHBLOCK,
        Action.LOWBLOCK: Action.HIGHKICK,
    }

    while agent.health > 0:
        action = await agent.act()
        await asyncio.sleep(random() * 0.2)

        neo_action = action_map[action]
        if action in {Action.HIGHBLOCK, Action.LOWBLOCK}:
            agent.health -= 1

        print(
            f"Agent{suffix}: {action}, Neo: {neo_action}, Agent{suffix} health: {agent.health}"
        )

    if print_win:
        print("Neo wins!")


if __name__ == "__main__":
    asyncio.run(fight())
