import argparse
import json
import logging
import os
import sys
from typing import Dict, List, Set

from dotenv import load_dotenv

load_dotenv("../.env")

logging.basicConfig(
    level=logging.INFO,
    stream=sys.stdout,
    format="%(message)s")


def json_to_obj():
    """
    Переводит json в объект python
    """
    json_file_path = os.getenv('WIKI_FILE')
    try:
        with open(json_file_path, 'r', encoding='utf-8') as f:
            json_data = json.load(f)
            return json_data
    except Exception:
        logging.info("database not found")
        sys.exit()


def jsonobj_to_graph(flag: bool) -> Dict[str, List[str]] | None:
    """
    Создает граф
    """
    jsonobj = json_to_obj()
    graph: Dict[str, List[str]] = {}
    edges = jsonobj["edges"]
    for edge in edges:
        if edge["source"] not in graph:
            graph[edge["source"]] = []
        graph[edge["source"]].append(edge["target"])
        if flag:
            if edge["target"] not in graph:
                graph[edge["target"]] = []
            graph[edge["target"]].append(edge["source"])
    return graph


def is_node_in_graph(node: str, graph: Dict[str, List[str]]) -> bool:
    """
    Checks if a given node exists in a graph.
    """
    return node in graph or any(node in neighbors for neighbors in graph.values())


def shortest_path(args) -> int:
    """
    Выводит результат
    """
    graph = jsonobj_to_graph(args.non_directed)
    start = args.from_
    finish = args.to
    if graph:
        if not is_node_in_graph(start, graph):
            logging.info(f"Start node: '{start}' not in graph")
            sys.exit()
        if not is_node_in_graph(finish, graph):
            logging.info(f"Finish node: '{finish}' not in graph")
            sys.exit()
        visited = set()
        path_list = counter(start, finish, graph, visited)
        path_list.reverse()
        if len(path_list) > 1:
            if args.v:
                print_path(path_list)
            print(len(path_list) - 1)
        else:
            logging.info('Path not found')
            sys.exit()


def print_path(path_list):
    """
    Выводит путь согласно примеру для флага -v
    """
    text = ''
    for i, _ in enumerate(path_list):
        if i != 0:
            text += ' -> '
        text += path_list[i]
    print(text)


def counter(start: str, finish: str, graph: Dict[str, List[str]], visited: Set):
    """
    Finds the shortest path using depth-first search.
    """

    visited.add(start)
    children = graph[start]
    count_min = []

    for child in children:
        if child not in visited:
            if child == finish:
                return [finish, start]
            if child in graph:
                count_for_child = counter(child, finish, graph, visited)
                if len(count_for_child) and (
                    len(count_min) == 0 or len(count_min) > len(count_for_child)
                ):
                    count_min = count_for_child
    if len(count_min):
        count_min.append(start)
    return count_min


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Cache Wikipedia pages.")
    parser.add_argument(
        "--from",
        dest="from_",
        help="Start link")
    parser.add_argument(
        "--to",
        help="Finish link")
    parser.add_argument(
        "--non-directed",
        dest='non_directed',
        help="Not directed",
        action='store_true')
    parser.add_argument(
        '-v',
        help='path to link',
        action='store_true'
    )
    args = parser.parse_args()

    shortest_path(args)
