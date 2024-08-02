"""
Exercise 03_01
"""

import argparse
import signal
import sys
from typing import List

import redis
from transaction import Transaction
from transaction_helper import *


def try_handle_evil(transaction: Transaction, evil: List[int]) -> Transaction:
    """
    Handle transactions involving evil accounts.

    Parameters
    ----------
    transaction : Transaction
        The transaction to potentially handle.
    evil : List[int]
        The list of evil account numbers.

    Returns
    -------
    Transaction
        The potentially modified transaction.
    """
    if transaction.reciver in evil and transaction.amount >= 0:
        transaction.sender, transaction.reciver = (
            transaction.reciver,
            transaction.sender,
        )
    return transaction


def consumer(evil: List[int]) -> None:
    """
    Consumes transactions from Redis pubsub and handles transactions involving evil accounts.

    Parameters
    ----------
    evil : List[int]
        The list of evil account numbers.

    Returns
    -------
    None
    """
    r: redis.Redis = redis.Redis()
    p: redis.client.PubSub = r.pubsub()
    p.subscribe("bad-guys")

    def signal_handler(sig, frame):
        print("Exiting gracefully...")
        p.unsubscribe()
        r.close()
        sys.exit(0)

    signal.signal(signal.SIGINT, signal_handler)

    print("Starting consumer: ")

    for msg in p.listen():
        if msg["type"] == "message":
            transaction: Transaction | None = decode_transaction(msg["data"])
            if transaction:
                transaction = try_handle_evil(transaction, evil)
                logger.warning(str(transaction))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-e", "--evil", help="list of evil customer's account number", type=str
    )
    args = parser.parse_args()

    if args.evil is not None and (
        not args.evil.replace(",", "").isnumeric()
        or not all(len(e) == 10 for e in args.evil.split(","))
    ):
        print("Bad argument")
        parser.print_usage()
        exit()

    evil = []
    if args.evil is not None:
        evil = [str(e) for e in args.evil.split(",")]

    consumer(evil)
