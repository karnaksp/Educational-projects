import redis
import logging
import argparse
from typing import *
from transaction import Transaction
from transaction_helper import decode_transaction


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
    if not transaction.amount < 0 and transaction.reciver in evil:
        return Transaction(
            reciver=transaction.reciver,
            sender=transaction.sender,
            amount=transaction.amount,
        )
    return transaction


def consumer(evil: List[int]) -> None:
    """
    Consumes transactions from Redis pubsub channel and handles transactions involving evil accounts.

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

    logger: logging.Logger = logging.getLogger()
    while p.get_message():
        pass

    while True:
        msg: Optional[Dict[str, Union[str, bytes]]] = p.get_message()
        if msg is None:
            continue

        if isinstance(msg["data"], (bytes)):
            transaction: Optional[Transaction] = decode_transaction(msg["data"])
            if transaction is None:
                continue

            transaction = try_handle_evil(transaction, evil)
            logger.warning(str(transaction))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-e", "--evil", help="list of evil customer's account number", type=str
    )
    args = parser.parse_args()

    if args.evil != None and (
        not args.evil.replace(",", "").isnumeric()
        or not all(len(e) == 10 for e in args.evil.split(","))
    ):
        print("Bad argument")
        parser.print_usage()
        exit()

    evil = []
    if args.evil != None:
        evil = [int(e) for e in args.evil.split(",")]

    print("Starting consumer: ")
    consumer(evil)
