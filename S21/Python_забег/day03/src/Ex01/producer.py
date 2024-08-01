import redis
import json
import logging
import time
from typing import *
from transaction import Transaction
from transaction_helper import interview_transaction


def producer() -> None:
    """
    Produce new transactions to the 'bad-guys' Redis channel.
    """
    r: redis.Redis = redis.Redis()

    logger: logging.Logger = logging.getLogger()
    i: int = 0
    while True:
        transaction: Optional[Transaction] = interview_transaction()
        if transaction is None:
            logger.warning("Bad transaction input. Go next")
            continue

        msg_json: str = json.dumps(transaction.__dict__)
        logger.warning("New transaction #%d made" % i)
        logger.warning(msg_json)

        r.publish("bad-guys", msg_json)
        time.sleep(3)
        i += 1


if __name__ == "__main__":
    print("Starting producer: ")
    producer()
