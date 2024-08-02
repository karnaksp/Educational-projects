from random import randint
import sys
import time
import argparse


def emit_gel(max_step):
    step = randint(0, max_step) if max_step > 0 else 0
    pressure = 0
    while True:
        reset = yield pressure
        if reset is not None:
            if (reset > 80 and step > 0) or (reset < 20 and step < 0):
                step = -step
        else:
            pressure += step

        if pressure > 100:
            pressure = 100
        elif pressure < 0:
            pressure = 0


def valve(max_step):
    gel = emit_gel(max_step)
    begin = True
    while True:
        try:
            pressure = next(gel)
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
        elif pressure > 80 or pressure < 20:
            gel.send(pressure)


if __name__ == "__main__":
    parcer = argparse.ArgumentParser(
        description=
        "Set max step for random generator and start valve generator")
    parcer.add_argument('s', default=30, nargs='?', type=int, help="max step")
    max_step = parcer.parse_args().s
    for p in valve(max_step):
        time.sleep(0.1)
        print(p, end=' ')
        sys.stdout.flush()
    print()
