from flask import Flask, request, render_template
from redis import Redis

from redis_configuration import PUBLISH_CHANEL
from transaction import Transaction
from transaction_helper import create_transaction
from transaction_redis_helper import publish_transaction

app = Flask(__name__)
publisher = Redis()

@app.route('/evilcorp')
def evilcorp():
    return render_template('evilcorp.html')

@app.route('/evilcorp_hacked')
def evilcorp_hacked():
    return render_template('evilcorp_hacked.html')

@app.route('/transfer', methods=['POST'])
def transfer():
    transaction = create_transaction(request.form["from"], request.form["to"], request.form["amount"])
    msg = publish_transaction(publisher, PUBLISH_CHANEL, transaction)
    return msg
