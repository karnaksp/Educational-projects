from itertools import zip_longest
from typing import Generator, Iterable, Optional


def fix_wiring(
    cables: Iterable[str], sockets: Iterable[str], plugs: Iterable[Optional[str]]
) -> Generator[str, None, None]:
    """
    Generator that yields commands to fix wiring.
    """
    cables = tuple(filter(lambda x: isinstance(x, str), cables))
    sockets = tuple(filter(lambda x: isinstance(x, str), sockets))
    plugs = tuple(filter(lambda x: isinstance(x, str) or x is None, plugs))
    for cable, socket, plug in zip_longest(
            cables, sockets, plugs, fillvalue=None):
        if cable is None or socket is None:
            continue
        if plug is None:
            yield f"weld {cable} to {socket} without plug"
        else:
            yield f"plug {cable} into {socket} using {plug}"
