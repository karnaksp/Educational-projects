import redis
import logging
import argparse

from transaction import Transaction
from transaction_helper import decode_transaction

def try_handle_evil(transaction: Transaction, evil: list[int]) -> Transaction:
    if not transaction.amount < 0 and transaction.reciver in evil:
        return Transaction(transaction.reciver, transaction.sender, transaction.amount)
    return transaction

def consumer(evil: list[str]):
    r = redis.Redis()
    p = r.pubsub()
    p.subscribe('bad-guys')

    logger = logging.getLogger()
    while p.get_message():
        pass

    while True:
        msg = p.get_message()
        if msg is None:
            continue
        
        if isinstance(msg['data'], (bytes)):
            transaction = decode_transaction(msg['data'])
            if transaction is None:
                continue

            transaction = try_handle_evil(transaction, evil)
            logger.warning(str(transaction))

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-e", "--evil", help="list of evil customer's account number", type=str)
    args = parser.parse_args()

    if args.evil != None and (not args.evil.replace(',', '').isnumeric() \
    or not all(len(e) == 10 for e in args.evil.split(','))):
        print('Bad argument')
        parser.print_usage()
        exit()

    evil = []
    if args.evil != None:
        evil = [ int(e) for e in args.evil.split(',')]

    print("Starting consumer: ")
    consumer(evil)

        