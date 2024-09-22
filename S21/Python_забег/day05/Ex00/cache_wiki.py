"""
Cache wiki pages
"""

import argparse
import asyncio
import json
import logging
import sys
from typing import Dict, List, Set, Tuple
from urllib.parse import quote, unquote

import aiohttp
from bs4 import BeautifulSoup
from db_wiki import save_to_neo4j
from diskcache import Cache

logging.basicConfig(
    level=logging.INFO,
    stream=sys.stdout,
    format="%(message)s")
logger: logging.Logger = logging.getLogger()
cache = Cache("./cache_directory")


async def fetch_page(session: aiohttp.ClientSession, url: str) -> str:
    """
    Fetches the webpage at the given URL
    and returns its HTML content as a string.
    """
    if url in cache:
        return cache[url]
    async with session.get(url) as response:
        response.raise_for_status()
        html: str = await response.text()
        cache[url] = html
        return html


def parse_links(html: str) -> Set[str]:
    """
    Given the HTML content of a webpage,
    return a set of all the links on the page.
    """
    soup = BeautifulSoup(html, "html.parser")
    links: Set[str] = set()
    for link in soup.find_all("a", href=True):
        href: str = link["href"]
        if href.startswith("/wiki/") and ":" not in href:
            page_title: str = href.split("/wiki/")[1]
            decoded_title: str = unquote(page_title)
            links.add(decoded_title)
    return links


async def visit_level(
    params: Tuple[
        aiohttp.ClientSession,
        str,
        List[Tuple[str, int]],
        set,
        dict,
        int,
        int,
        asyncio.Event,
    ]
) -> List[Tuple[str, int]]:
    """
    Processes the current level of pages to visit.
    """
    session, base_url, to_visit, visited, graph, depth, max_pages, stop_event = params

    current_level_tasks = []
    page_to_fetch = []

    for current_page, current_depth in to_visit:
        if current_depth > depth:
            logging.info("\nReached the maximum depth.")
            stop_event.set()
            break
        if current_page in visited:
            continue
        if len(visited) >= max_pages:
            logging.info("\nReached the maximum number of pages.")
            stop_event.set()
            break
        visited.add(current_page)
        url = base_url + quote(current_page)
        logging.info("Visiting: %s", unquote(current_page).replace("_", " "))
        task = fetch_page(session, url)
        current_level_tasks.append((task, current_page, current_depth))

    for task, page, depth_cur in current_level_tasks:
        try:
            html = await task
            links = parse_links(html)
            graph[page] = list(links)
            for link in links:
                if link not in visited and len(visited) < max_pages:
                    page_to_fetch.append((link, depth_cur + 1))
        except aiohttp.ClientResponseError as e:
            logging.error("Failed to fetch page with error: %s", e)

    return page_to_fetch


def create_json(graph: Dict[str, List[str]], filename: str):
    """
    Creates JSON file like a graph.
    """
    nodes = list(graph.keys())
    edges = [
        {"source": source, "target": target}
        for source, targets in graph.items()
        for target in targets
    ]
    graph_json = {"nodes": nodes, "edges": edges}
    with open(filename, "w", encoding="utf-8") as f:
        json.dump(graph_json, f, ensure_ascii=False, indent=2)


async def cache_wiki(start_page: str, depth: int, max_pages: int) -> None:
    """
    Cache Wikipedia pages.
    """
    base_url: str = "https://en.wikipedia.org/wiki/"
    visited: Set[str] = set()
    graph: Dict[str, List[str]] = {}
    to_visit: List[Tuple[str, int]] = [(start_page, 0)]
    stop_event: asyncio.Event = asyncio.Event()

    async with aiohttp.ClientSession() as session:
        while to_visit:
            if stop_event.is_set():
                break

            to_visit = await visit_level(
                (
                    session,
                    base_url,
                    to_visit,
                    visited,
                    graph,
                    depth,
                    max_pages,
                    stop_event,
                )
            )

    create_json(graph, "wiki.json")
    save_to_neo4j(graph)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Cache Wikipedia pages.")
    parser.add_argument(
        "-p",
        "--page",
        default="Erdős_number",
        help="Starting page")
    parser.add_argument(
        "-d",
        "--depth",
        type=int,
        default=3,
        help="Depth of traversal")
    parser.add_argument(
        "-m", "--max_pages", type=int, default=1000, help="Maximum pages for cache"
    )
    args = parser.parse_args()
    asyncio.run(cache_wiki(args.page, args.depth, args.max_pages))
