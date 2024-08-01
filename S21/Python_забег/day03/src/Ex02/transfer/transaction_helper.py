from transaction import Transaction
import json

def is_valid_account_number(account_number: str) -> bool:
    if len(account_number) != 10 or not account_number.isdigit():
        return False
    return True

def is_valid_amount(amount: str) -> bool:
    return amount.isdecimal() \
        or len(amount) > 1 and amount[0] == '-' and amount[1:].isdecimal() \
        or len(amount) > 1 and amount[0] == '.' and amount[1:].isdecimal() \
        or len(amount) > 2 and amount[0] == '-' and amount[1] == '.' and amount[2:].isdecimal()

def valid_transaction(sender: str, reciver:str, amount: str) -> bool:
    if not is_valid_account_number(sender) \
    or not is_valid_account_number(reciver) \
    or not is_valid_amount(amount):
        return False
    return True

def create_transaction(sender: str, reciver: str, amount: str) -> Transaction:
    if not valid_transaction(sender, reciver, amount):
        return None
    return Transaction(int(sender), int(reciver), float(amount))

def interview_transaction() -> Transaction:
    print('Enter transaction details:')
    sender = input('Sender account (10 digits):  ')
    reciver = input('Reciver accoun (10 digits)t: ')
    amount = input('Amount: ')
    return create_transaction(sender, reciver, amount)

def decode_transaction(msg: bytes) -> Transaction:
    obj = json.loads(msg)
    if 'sender' in obj and 'reciver' in obj and 'amount' in obj:
        return Transaction(obj['sender'], obj['reciver'], obj['amount'])
    return None