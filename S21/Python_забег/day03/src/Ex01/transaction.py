import json


class Transaction(object):
    """
    Class for managing transactions.
    """

    def __init__(self, sender: int, reciver: int, amount: float):
        """
        Initialize a new transaction.

        Parameters
        ----------
        sender : int
            The sender of the transaction.
        reciver : int
            The recipient of the transaction.
        amount : float
            The amount of the transaction.
        """
        self.sender = sender
        self.reciver = reciver
        self.amount = amount

    def __str__(self):
        """
        Return a JSON string representing the transaction.

        Returns
        -------
        str
            A JSON string containing metadata and amount.
        """
        return json.dumps(
            {
                "metadata": {"from": self.sender, "to": self.reciver},
                "amount": self.amount,
            }
        )
