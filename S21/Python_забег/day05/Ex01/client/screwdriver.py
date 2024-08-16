import sys
import requests
from bs4 import BeautifulSoup

SERVER_URL = "http://127.0.0.1:8888"


def upload_file(file_path):
    with open(file_path, "rb") as f:
        file_name = file_path.split("/")[-1]
        files = {"file": (file_name, f)}
        response = requests.post(SERVER_URL, files=files)
        soup = BeautifulSoup(response.text, "html.parser")
        error_alert = soup.find("div", {"class": "alert alert-info"})
        print(error_alert.get_text(strip=True))


def list_files():
    response = requests.get(SERVER_URL)
    if response.ok:
        print("Uploaded files:")
        soup = BeautifulSoup(response.text, "html.parser")
        files = [li.contents[0].strip() for li in soup.select("ul li")]
        for i, file in enumerate(files):
            print(f"{i+1}) {file}")
    else:
        print("Failed to retrieve files")


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage:")
        print("  python screwdriver.py upload /path/to/file.mp3")
        print("  python screwdriver.py list")
        sys.exit(1)

    action = sys.argv[1]

    if action == "upload" and len(sys.argv) == 3:
        upload_file(sys.argv[2])
    elif action == "list":
        list_files()
    else:
        print("Invalid command")
