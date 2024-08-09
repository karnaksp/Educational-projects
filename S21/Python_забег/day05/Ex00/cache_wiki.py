import requests
from bs4 import BeautifulSoup
import json
import argparse
import logging
from urllib.parse import urljoin

# Setup logging
logging.basicConfig(level=logging.INFO)


def fetch_page(url):
    response = requests.get(url)
    response.raise_for_status()
    return response.text


def parse_links(html, base_url):
    soup = BeautifulSoup(html, "html.parser")
    links = set()
    for link in soup.find_all("a", href=True):
        href = link["href"]
        if href.startswith("/wiki/") and ":" not in href:
            full_url = urljoin(base_url, href)
            page_title = href.split("/wiki/")[1]
            links.add(page_title)
    return links


def cache_wiki(start_page, depth, max_pages):
    base_url = "https://en.wikipedia.org/wiki/"
    visited = set()
    graph = {}
    to_visit = [(start_page, 0)]

    while to_visit:
        current_page, current_depth = to_visit.pop(0)
        if current_page in visited or current_depth > depth:
            continue
        visited.add(current_page)
        url = base_url + current_page
        logging.info(f"Visiting: {current_page}")
        html = fetch_page(url)
        links = parse_links(html, base_url)
        graph[current_page] = list(links)
        for link in links:
            if link not in visited:
                to_visit.append((link, current_depth + 1))
        if len(visited) >= max_pages:
            break

    with open("wiki.json", "w") as f:
        json.dump(graph, f, indent=2)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Cache Wikipedia pages.")
    parser.add_argument("-p", "--page", default="Harry_Potter", help="Starting page")
    parser.add_argument("-d", "--depth", type=int, default=3, help="Depth of traversal")
    args = parser.parse_args()

    cache_wiki(args.page, args.depth, 10)
