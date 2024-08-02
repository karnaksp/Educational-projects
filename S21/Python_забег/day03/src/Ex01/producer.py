import time
from typing import *

import redis
from transaction import Transaction
from transaction_helper import *


def producer() -> None:
    """
    Produce new transactions to the 'bad-guys' Redis channel.
    """
    r: redis.Redis = redis.Redis()
    i: int = 0
    while True:
        transaction: Transaction | None = interview_transaction()
        if transaction is None:
            logger.warning("Bad transaction input. Go next")
            continue

        logger.warning("New transaction #%d made" % i)
        logger.warning(str(transaction))

        r.publish("bad-guys", str(transaction))
        time.sleep(3)
        i += 1


if __name__ == "__main__":
    print("Starting producer!")
    producer()
