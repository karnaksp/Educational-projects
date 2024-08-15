"""
Variety of ships and other params.
"""

ALIGNMENTS = ["ALLY", "ENEMY"]
NAMES = ["Normandy", "Executor", "Unknown", "Galactica", "Enterprise", "Voyager"]
CLASSES = ["CORVETTE", "FRIGATE", "CRUISER", "DESTROYER", "CARRIER", "DREADNOUGHT"]
LENGTH_RANGE = (80.0, 20000.0)
CREW_SIZE_RANGE = (0, 500)
ARMED_STATUS = [True, False]
HOSTILE_STATUS = [True, False]
OFFICER_NAMES = [
    {"first_name": "John", "last_name": "Doe", "rank": "Captain"},
    {"first_name": "Jane", "last_name": "Smith", "rank": "Commander"},
    {"first_name": "Alan", "last_name": "Shepard", "rank": "Lieutenant"},
    {"first_name": "Ellen", "last_name": "Ripley", "rank": "Sergeant"},
    {"first_name": "James", "last_name": "T. Kirk", "rank": "Captain"},
    {"first_name": "Jean-Luc", "last_name": "Picard", "rank": "Admiral"},
    {"first_name": "Ellen-Luc", "last_name": "Picard", "rank": "Lieutenant"},
    {"first_name": "John-Luc", "last_name": "Picard", "rank": "Sergeant"},
    {"first_name": "Alan-Luc", "last_name": "Picard", "rank": "Lieutenant"},
    {"first_name": "Jean-Luc", "last_name": "Picard", "rank": "Sergeant"},
    {"first_name": "Ellen-Luc", "last_name": "Picard", "rank": "Captain"},
]
OFFICER_COUNT_RANGE = (1, 10)
