import json

class Transaction(object):

    def __init__(self, sender: int, reciver: int, amount: float):
        self.sender = sender
        self.reciver = reciver
        self.amount = amount

    def __str__(self):
        return json.dumps({"metadata": {"from": self.sender, "to": self.reciver}, "amount": self.amount})