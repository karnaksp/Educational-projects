import time

from pressure import valve


def main():
    """Main function to run the valve control for a short duration."""
    print("-------------------------------------")
    max_step = 20
    pressure_control = valve(max_step)
    print(f"Max step: {max_step}")
    start_time = time.time()
    while time.time() - start_time < 5:
        try:
            pressure = next(pressure_control)
            print(f"Current pressure: {pressure}")
            time.sleep(0.1)
        except StopIteration:
            print("Stop iteration reached")
            break
    print("-------------------------------------")


if __name__ == "__main__":
    main()
