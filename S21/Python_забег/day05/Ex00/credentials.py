"""
wsgi server
"""

from wsgiref.simple_server import make_server
import json
from urllib.parse import parse_qs

SP_DIC: dict[str, str] = {
    "Cyberman": "John Lumic",
    "Dalek": "Davros",
    "Judoon": "Shadow Proclamation Convention 15 Enforcer",
    "Human": "Leonardo da Vinci",
    "Ood": "Klineman Halpen",
    "Silence": "Tasha Lem",
    "Slitheen": "Coca-Cola salesman",
    "Sontaran": "General Staal",
    "Time Lord": "Rassilon",
    "Weeping Angel": "The Division Representative",
    "Zygon": "Broton",
}


def application(environ, start_response):
    query_string = environ.get("QUERY_STRING", "")
    params = parse_qs(query_string)
    requested_species = params.get("species", [None])[0]
    if not requested_species or not isinstance(requested_species, str):
        response_body = json.dumps({"error": "Invalid input"}, indent=4) + "\n"
        status = "400 Bad Request"
        headers = _get_headers(response_body)
    else:
        response_body = _get_response_body(requested_species)
        headers = _get_headers(response_body)
        status = _get_status(requested_species)
    start_response(status, headers)
    return [response_body.encode("utf-8")]


def _get_response_body(requested_species):
    if requested_species and requested_species in SP_DIC:
        leader_name = SP_DIC[requested_species]
        return json.dumps({"credentials": leader_name}, indent=4) + "\n"
    return json.dumps({"credentials": "Unknown"}, indent=4) + "\n"


def _get_status(requested_species):
    return (
        "200 OK"
        if requested_species and requested_species in SP_DIC
        else "404 Not Found"
    )


def _get_headers(response_body):
    return []


if __name__ == "__main__":
    with make_server("", 8888, application) as httpd:
        httpd.serve_forever()
