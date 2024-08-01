"""
Behavior types
"""

import random

from base_player import Player


class Cheater(Player):
    """Always cheats"""

    def __init__(self):
        super().__init__()

    def play(self, opponent_history):
        return "cheat"


class Cooperator(Player):
    """Always cooperate"""

    def __init__(self):
        super().__init__()

    def play(self, opponent_history):
        return "cooperate"


class Copycat(Player):
    """Starts with cooperating,
    but then just repeats whatever the other guy is doing"""

    def __init__(self):
        super().__init__()

    def play(self, opponent_history):
        if not opponent_history:
            return "cooperate"
        return opponent_history[-1]


class Grudger(Player):
    """Starts by always cooperating,
    but switches to Cheater forever if another guy cheats even once"""

    def __init__(self):
        super().__init__()
        self.grudge = False

    def play(self, opponent_history):
        if "cheat" in opponent_history:
            self.grudge = True
        return "cheat" if self.grudge else "cooperate"


class Detective(Player):
    """First four times goes with [Cooperate, Cheat, Cooperate, Cooperate],
    and if during these four turns another guy cheats even once —
    switches into a Copycat. Otherwise, switches into Cheater himself"""

    def __init__(self):
        super().__init__()
        self.moves = ["cooperate", "cheat", "cooperate", "cooperate"]
        self.is_copycat = False

    def play(self, opponent_history):
        if len(self.history) < 4:
            move = self.moves[len(self.history)]
        else:
            if "cheat" in opponent_history[:4]:
                self.is_copycat = True
            move = opponent_history[-1] if self.is_copycat else "cheat"
        return move


class Randomer(Player):
    """A player that chooses its move at random."""

    def play(self, opponent_history):
        return random.choice(["cooperate", "cheat"])
