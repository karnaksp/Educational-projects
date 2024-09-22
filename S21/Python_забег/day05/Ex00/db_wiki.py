"""
Database neo4j init
"""

import logging
import sys
from typing import Dict, List

from neo4j import GraphDatabase

logging.basicConfig(
    level=logging.INFO,
    stream=sys.stdout,
    format="%(message)s")

NEO4J_URI = "bolt://neo4j:7687"
NEO4J_USER = "neo4j"
NEO4J_PASSWORD = "assassass"
NEO4J_DRIVER = GraphDatabase.driver(
    NEO4J_URI, auth=(NEO4J_USER, NEO4J_PASSWORD))


def clear_neo4j_database(session) -> None:
    """
    Clears the Neo4j database.
    """
    session.run("MATCH (n) DETACH DELETE n")
    logging.info("Neo4j database cleared.")


def save_to_neo4j(graph: Dict[str, List[str]]) -> None:
    """
    Saves a graph represented as a dictionary of nodes
    and their adjacent nodes to a Neo4j database.
    """
    logging.info("Starting save_to_neo4j function.")

    try:
        session = NEO4J_DRIVER.session()
        logging.info("Neo4j session started.")
        clear_neo4j_database(session)
        if not graph:
            logging.info("Graph is empty. No data to save.")
            return
        for node in list(graph.keys()):
            session.run("MERGE (n:Page {title: $title})", title=node)

        for source, targets in graph.items():
            for target in targets:
                session.run(
                    """
                    MATCH (a:Page {title: $source})
                    MATCH (b:Page {title: $target})
                    MERGE (a)-[:LINKS_TO]->(b)
                """,
                    source=source,
                    target=target,
                )

        logging.info("Graph data saved to Neo4j successfully.")

    except Exception:
        logging.info("An error occurred while saving to Neo4j.", exc_info=True)
    finally:
        session.close()
        logging.info("Neo4j session closed.")
        NEO4J_DRIVER.close()
        logging.info("Neo4j driver closed.")
