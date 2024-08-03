import random
from typing import Generator, Optional


def emit_gel(max_step: int) -> Generator[int, Optional[int], None]:
    """
    Generator function that emits a random pressure value within a given range.
    """
    pressure = random.randint(0, 100)
    step = random.randint(0, max_step) if max_step > 0 else 0
    print(f"Choose step: {step}")
    while True:
        try:
            reset = yield pressure
            if reset is not None:
                if (pressure > 80 and step > 0) or (pressure < 20 and step < 0):
                    step = -step
        except GeneratorExit:
            break
        pressure += step
        pressure = max(0, min(100, pressure))


def valve(max_step: int) -> Generator[int, None, None]:
    """
    Control the pressure within the operating range.
    """
    gel = emit_gel(max_step)
    begin = True
    while True:
        try:
            pressure: int = next(gel)
        except StopIteration:
            break

        yield pressure

        if begin:
            if pressure > 9:
                begin = False
                if pressure > 80:
                    gel.send(pressure)
        elif pressure > 90 or pressure < 10:
            gel.close()
            break
        elif pressure > 80 or pressure < 20:
            gel.send(pressure)
