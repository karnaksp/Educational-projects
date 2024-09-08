"""
Module for rendering and visualizing a graph.
"""

import argparse
import json
import os

import matplotlib.pyplot as plt
import networkx as nx
import plotly.graph_objects as go
import scipy
from dotenv import load_dotenv


def load_graph_from_json(json_file_path):
    """
    Loads a graph from a JSON file.
    """
    with open(json_file_path, "r", encoding="utf-8") as file:
        return json.load(file)


def create_networkx_graph(graph_json):
    """
    Creates a NetworkX directed graph from a JSON representation of a graph.
    """
    graph = nx.DiGraph()
    for node in graph_json["nodes"]:
        graph.add_node(node)
    for edge in graph_json["edges"]:
        graph.add_edge(edge["source"], edge["target"])
    return graph


def visualize_graph_png(graph, output_file_path):
    """
    Visualizes a graph as a PNG image.
    """
    position = nx.spring_layout(graph, seed=42)
    node_sizes = [graph.in_degree(node) * 100 for node in graph.nodes()]
    plt.figure(figsize=(12, 12), dpi=60)
    nx.draw(
        graph,
        position,
        with_labels=False,
        node_size=node_sizes,
        node_color="skyblue",
        arrows=True,
    )
    plt.title("Graph Visualization")
    plt.savefig(output_file_path, format="png")
    plt.close()


def visualize_graph_html(graph, output_file_path):
    """
    Visualizes a graph as an interactive HTML file.
    """
    position = nx.spring_layout(graph, seed=42)
    edge_trace = []
    node_trace = []

    for edge in graph.edges():
        x0, y0 = position[edge[0]]
        x1, y1 = position[edge[1]]
        edge_trace.append(
            go.Scatter(
                x=[x0, x1, None],
                y=[y0, y1, None],
                mode="lines",
                line={"width": 0.5, "color": "#888"},
            )
        )

    for node in graph.nodes():
        x, y = position[node]
        node_trace.append(
            go.Scatter(
                x=[x],
                y=[y],
                mode="markers+text",
                marker={
                    "size": graph.in_degree(node) * 10,
                    "color": "skyblue",
                    "line": {"width": 2},
                },
                text=[node],
                textposition="bottom center",
            )
        )

    fig = go.Figure(
        data=edge_trace + node_trace,
        layout=go.Layout(
            showlegend=False,
            xaxis={"showgrid": False, "zeroline": False},
            yaxis={"showgrid": False, "zeroline": False},
        ),
    )
    fig.write_html(output_file_path)


def main():
    """
    The main function that renders and visualizes a graph from a JSON file.
    """
    parser = argparse.ArgumentParser(
        description="Render and visualize a graph.")
    parser.add_argument(
        "json_file",
        nargs="?",
        default=None,
        help="Path to the JSON file containing the graph.",
    )
    parser.add_argument("png_output", help="Path to the output PNG file.")
    parser.add_argument(
        "--html-output", help="Path to the output HTML file (optional)."
    )
    args = parser.parse_args()
    json_file = os.getenv("WIKI_FILE") or args.json_file
    if not json_file:
        raise ValueError(
            "No input JSON file. Set WIKI_FILE environment or provide file."
        )
    graph_json = load_graph_from_json(json_file)
    graph = create_networkx_graph(graph_json)
    visualize_graph_png(graph, args.png_output)
    if args.html_output:
        visualize_graph_html(graph, args.html_output)


if __name__ == "__main__":
    load_dotenv("../.env")
    main()
