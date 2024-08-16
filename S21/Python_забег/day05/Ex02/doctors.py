import threading
import time
import random


class Screwdriver:
    def __init__(self, id):
        self.id = id
        self.lock = threading.Lock()


class Doctor(threading.Thread):
    def __init__(self, id, screwdrivers):
        super().__init__()
        self.id = id
        self.screwdrivers = screwdrivers
        self.screwdrivers_needed = 2
        self.screwdriver_locks = []

    def run(self):
        while not self.grab_screwdrivers():
            time.sleep(random.uniform(0.1, 0.5))
        self.perform_blast()

    def grab_screwdrivers(self):
        random.shuffle(self.screwdrivers)
        self.screwdriver_locks = [self.screwdrivers[0].lock, self.screwdrivers[1].lock]
        acquired = [lock.acquire(timeout=0.1) for lock in self.screwdriver_locks]

        if all(acquired):
            return True
        else:
            for lock, was_acquired in zip(self.screwdriver_locks, acquired):
                if was_acquired:
                    lock.release()
            return False

    def perform_blast(self):
        print(f"Doctor {self.id}: BLAST!")
        time.sleep(random.uniform(0.1, 0.5))
        for lock in self.screwdriver_locks:
            if lock.locked():
                lock.release()


def main():
    screwdrivers = [Screwdriver(i) for i in range(5)]
    doctors = [Doctor(i, screwdrivers) for i in range(9, 14)]
    for doctor in doctors:
        doctor.start()
    for doctor in doctors:
        doctor.join()


if __name__ == "__main__":
    main()
