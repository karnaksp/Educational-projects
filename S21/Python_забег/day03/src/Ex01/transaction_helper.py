import json
import logging
from typing import *

from transaction import Transaction

logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(message)s")
logger = logging.getLogger()


def is_valid_account_number(account_number: str) -> bool:
    """
    Check if the given account number is valid.

    Parameters
    ----------
    account_number : str
        The account number to be checked.

    Returns
    -------
    bool
        True if the account number is valid, False otherwise.
    """
    return len(account_number) == 10 and account_number.isdigit()


def is_valid_amount(amount: str) -> bool:
    """
    Check if the given amount is valid.

    Parameters
    ----------
    amount : str
        The amount to be checked.

    Returns
    -------
    bool
        True if the amount is valid, False otherwise.
    """
    try:
        float(amount)  # type: ignore
        return True
    except ValueError:
        pass

    if len(amount) > 1:
        if amount[0] == "-" and amount[1:].isdecimal():
            return True
        if amount[0] == "." and amount[1:].isdecimal():
            return True
        if (
            len(amount) > 2
            and amount[0] == "-"
            and amount[1] == "."
            and amount[2:].isdecimal()
        ):
            return True

    return False


def valid_transaction(sender: str, reciver: str, amount: str) -> bool:
    """
    Check if the given sender, reciver and amount are valid.

    Parameters
    ----------
    sender : str
        The sender of the transaction.
    reciver : str
        The recipient of the transaction.
    amount : str
        The amount of the transaction.

    Returns
    -------
    bool
        True if the sender, reciver and amount are valid, False otherwise.
    """
    return (
        is_valid_account_number(sender)
        and is_valid_account_number(reciver)
        and is_valid_amount(amount)
    )


def create_transaction(sender: str, reciver: str,
                       amount: str) -> Optional[Transaction]:
    """
    Create a new transaction.

    Parameters
    ----------
    sender : str
        The sender of the transaction (10 digits).
    reciver : str
        The recipient of the transaction (10 digits).
    amount : str
        The amount of the transaction (float).

    Returns
    -------
    Optional[Transaction]
        A new Transaction object if the sender, reciver and amount are valid,
        None otherwise.
    """
    if not valid_transaction(sender, reciver, amount):
        return None
    return Transaction(str(sender), str(reciver), float(amount))


def interview_transaction() -> Transaction:
    """
    Prompt the user for transaction details and create a new Transaction object.

    Returns
    -------
    Transaction
        A new Transaction object created from the user's input.
    """
    print("Enter transaction details below.")
    sender: str = input("Sender account (10 digits):  ")
    reciver: str = input("Receiver account (10 digits): ")
    amount: str = input("Amount: ")
    return create_transaction(sender, reciver, amount)


def decode_transaction(msg: bytes) -> Optional[Transaction]:
    """
    Decode a transaction from a JSON message.

    Parameters
    ----------
    msg : bytes
        The JSON message containing the transaction details.

    Returns
    -------
    Optional[Transaction]
        A new Transaction object if the message is valid, None otherwise.
    """
    try:
        msg_str = msg.decode("utf-8")
        # logger.info(f"Received message: {msg_str}")
        obj: Dict[str, Union[int, float]] = json.loads(msg_str)
        if (
            "metadata" in obj
            and "from" in obj["metadata"]
            and "to" in obj["metadata"]
            and "amount" in obj
        ):
            return Transaction(
                obj["metadata"]["from"], obj["metadata"]["to"], obj["amount"]
            )
    except (json.JSONDecodeError, KeyError, TypeError) as e:
        logger.error(f"Failed to decode transaction: {e}")
    return None
