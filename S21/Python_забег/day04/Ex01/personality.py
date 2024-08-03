import random
from typing import Generator, List, Tuple, Type


def random_by_total(total: int = 100, count: int = 5) -> Tuple[int, ...]:
    """
    Generates random values,
    with their sum equal to total.
    """
    if total <= 0 or count <= 0:
        raise ValueError(
            "Total must be greater than 0 and count must be greater than 0"
        )
    if total <= count:
        raise ValueError("Total is too small for the given count")
    remaining: int = total
    traits: List[int] = []
    for _ in range(count - 1):
        value: int = random.randint(0, min(remaining, count))
        traits.append(value)
        remaining -= value
    traits.append(remaining)
    return tuple(traits)


def create_turret_class(
    neuro: int, openn: int, cons: int, extra: int, agree: int
) -> Type:
    """
    Creates a Turret class with the given personality traits.
    """
    return type(
        "Turret",
        (),
        {
            "name": "Turret",
            "shoot": lambda self: print("Shooting"),
            "search": lambda self: print("Searching"),
            "talk": lambda self: print("Talking"),
            "neuroticism": neuro,
            "openness": openn,
            "conscientiousness": cons,
            "extraversion": extra,
            "agreeableness": agree,
        },
    )


def turrets_generator() -> Generator[Type, None, None]:
    """
    Generates an infinite generator of Turret classes
    with randomly generated personality traits.
    """
    while True:
        traits: Tuple[int] = random_by_total(count=5)
        yield create_turret_class(*traits)
