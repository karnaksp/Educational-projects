from redis import Redis
import json
import logging

from transaction import Transaction

def publish_transaction(redis_instance, chanel_name: str, transaction: Transaction) -> str:
    logger = logging.getLogger()

    if transaction is None:
        logger.warning('Bad transaction input. Go next')
        return
    
    msg_json = json.dumps(transaction.__dict__)

    logger.warning("Made new transaction \n%s" % transaction)
    logger.warning(msg_json)
    
    redis_instance.publish(chanel_name, msg_json)
    return msg_json