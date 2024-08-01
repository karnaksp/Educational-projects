"""
Base classes for Game
"""


class Player:
    """
    Base class for all players in the game.

    Attributes
    ----------
    history : list
        List of moves made by the player.
    """

    def __new__(cls):
        """
        Create a new instance of the class and initialize the `history` attribute.

        Parameters
        ----------
        cls : type
            The class object.

        Returns
        -------
        Player
            An instance of the `Player` class.
        """
        instance = super(Player, cls).__new__(cls)
        instance.history = []
        return instance

    def __init__(self):
        """
        Initialize the `history` attribute.
        """
        self.history = []

    def play(self, opponent_history):
        """
        Determine the player's move based on the opponent's history.

        Parameters
        ----------
        opponent_history : list
            List of moves made by the opponent.

        Returns
        -------
        str
            The player's move.
        """
        pass

    def record_opponent_move(self, move):
        """
        Record the opponent's move in the player's history.

        Parameters
        ----------
        move : str
            The opponent's move.
        """
        self.history.append(move)
