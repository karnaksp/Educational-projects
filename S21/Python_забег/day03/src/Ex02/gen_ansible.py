"""
Exercise 03_02
"""

import argparse
import glob
import os
from typing import Dict, List, Optional, Union

import yaml


def remove_first_line_dash(file_path: str) -> None:
    """
    Remove the first line of a file if it starts with "- ".
    """
    with open(file_path, "r") as file:
        lines: List[str] = file.readlines()

    if lines and lines[0].startswith("- "):
        lines[0] = lines[0][2:]

    with open(file_path, "w") as file:
        file.writelines(lines)


def get_filename_recursive(directory: str, filename: str) -> Optional[str]:
    """
    Find the full path of a file recursively in a directory.
    """
    files = glob.glob(os.path.join(directory, "**", filename), recursive=True)
    return files[0] if files else None


def generate_ansible(src_root_directory: str, dest_directory: str) -> None:
    """
    Generate the Ansible playbook based on the todo.yml configuration.
    """
    todo_file_path: str = os.path.join(
        src_root_directory, "materials/todo.yml")
    if not os.path.exists(todo_file_path):
        raise FileNotFoundError(f"'{todo_file_path}' does not exist.")
    with open(todo_file_path, "r") as stream:
        todo: Dict[str, Union[str, List[str]]] = yaml.safe_load(stream)

    deploy: List[Dict[str, Union[str, List[Dict[str, Union[str, Dict[str, str]]]]]]] = [
        {"name": "Deploy Evil Corp Exploit", "hosts": "myhosts", "tasks": []}
    ]
    deploy[0]["tasks"].append(
        {
            "name": "Update package repositories",
            "ansible.builtin.apt": {"update_cache": True},
        }
    )
    for package_name in todo.get("server", {}).get("install_packages", []):
        deploy[0]["tasks"].append(
            {
                "name": f"Install package {package_name}",
                "ansible.builtin.apt": {"name": package_name, "state": "present"},
            }
        )
    for file_name in todo.get("server", {}).get("exploit_files", []):
        file_full_path: Optional[str] = get_filename_recursive(
            src_root_directory, file_name
        )
        if file_full_path is None:
            raise FileNotFoundError(
                f'No file "{file_name}" found in directory {src_root_directory}'
            )
        deploy[0]["tasks"].append(
            {
                "name": f"Copy file {os.path.basename(file_name)}",
                "ansible.builtin.copy": {
                    "src": file_full_path,
                    "dest": os.path.join(dest_directory, os.path.basename(file_name)),
                },
            }
        )
    bad_guys: str = ",".join(todo.get("bad_guys", []))
    deploy[0]["tasks"].append(
        {
            "name": "Run Python pub/sub transactions consumer",
            "ansible.builtin.shell": f'python3 {os.path.join(dest_directory, "consumer.py")} -e {bad_guys}',
        }
    )
    with open("../../materials/deploy.yml", "w", encoding="utf8") as output:
        yaml.dump(deploy, output, default_flow_style=False)
    remove_first_line_dash("../../materials/deploy.yml")


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description="Generate Ansible playbook from todo.yml"
    )
    parser.add_argument(
        "-s", "--source", help="Source directory", default=".", type=str
    )
    parser.add_argument(
        "-d", "--destination", help="Destination directory", default="~", type=str
    )
    args = parser.parse_args()
    try:
        generate_ansible(args.source, os.path.expanduser(args.destination))
    except Exception as e:
        print(f"Error: {e}")
