"""
Game model
"""

from collections import Counter


class Game:
    """
    A class that models a game between two players.

    Attributes
    ----------
    matches : int
        The number of matches in a game.
    registry : Counter
        A Counter object that keeps track of the score of each player in the game.

    Methods
    -------
    __init__(matches=10)
        Initialize a Game object with the number of matches.
    play(player1, player2)
        Play a game between two players. Update the score of each player in the registry.
    top3()
        Print the top 3 players with their scores.
    """

    def __init__(self, matches=10):
        """
        Initialize a Game object with the number of matches.

        Parameters
        ----------
        matches : int, optional
            The number of matches in a game. Default is 10.
        """
        self.matches = matches
        self.registry = Counter()

    def play(self, player1, player2):
        """
        Play a game between two players. Update the score of each player in the registry.

        Parameters
        ----------
        player1 : Player
            The first player.
        player2 : Player
            The second player.
        """
        player1_score, player2_score = 0, 0

        for _ in range(self.matches):
            move1 = player1.play(player2.history)
            move2 = player2.play(player1.history)
            player1.record_opponent_move(move2)
            player2.record_opponent_move(move1)

            if move1 == "cooperate" and move2 == "cooperate":
                player1_score += 2
                player2_score += 2
            elif move1 == "cheat" and move2 == "cooperate":
                player1_score += 3
                player2_score -= 1
            elif move1 == "cooperate" and move2 == "cheat":
                player1_score -= 1
                player2_score += 3
            elif move1 == "cheat" and move2 == "cheat":
                player1_score += 0
                player2_score += 0

        self.registry[type(player1).__name__] += player1_score
        self.registry[type(player2).__name__] += player2_score

    def top3(self):
        """
        Print the top 3 players with their scores.
        """
        top_players = self.registry.most_common(3)
        for player, score in top_players:
            print(f"{player} {score}")
