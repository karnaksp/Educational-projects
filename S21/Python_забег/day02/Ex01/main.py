"""
Exercise 02_01
"""

from typing import List

from behavior import *
from game import Game


def simulate_games(players: List[Player], matches: int = 10) -> None:
    """
    Simulate games between all pairs of players.

    Args:
        players (List[Player]): List of players.
        matches (int, optional): Number of matches per game.
        Default is 10.

    """
    game = Game(matches=matches)
    for i, player1 in enumerate(players):
        for j, player2 in enumerate(players):
            if i != j:
                game.play(player1, player2)

    game.top3()


if __name__ == "__main__":
    simulate_games(
        [Cheater(), Cooperator(), Copycat(), Grudger(), Detective(), Randomer()]
    )
