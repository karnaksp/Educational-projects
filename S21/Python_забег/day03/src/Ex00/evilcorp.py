"""
Ex 03_00
"""

from bs4 import BeautifulSoup


class EvilCorpHacker:
    """
    Class for hacking EvilCorp's page
    """

    def __init__(self, input_file: str, output_file: str) -> None:
        """
        Initialize EvilCorpHacker

        Parameters
        ----------
        input_file : str
            path to input file with html
        output_file : str
            path to output file with hacked html
        """
        self.input_file = input_file
        self.output_file = output_file

    def read_file(self) -> str:
        """
        Read file and return content

        Returns
        -------
        str
            content of file
        """
        with open(self.input_file, "r", encoding="utf-8") as file:
            return file.read()

    def write_file(self, content: str) -> None:
        """
        Write content to file

        Parameters
        ----------
        content : str
            content to write
        """
        with open(self.output_file, "w", encoding="utf-8") as file:
            file.write(content)

    def hack_page(self) -> None:
        """
        Hack page
        """
        html_content = self.read_file()
        soup = BeautifulSoup(html_content, "html.parser")
        if soup.title:
            soup.title.string = "Evil Corp - Stealing your money every day"
        h1_tag = soup.find("h1")
        user_name = h1_tag.string.strip() if h1_tag and h1_tag.string else "User"
        new_h1_tag = soup.new_tag("h1")
        new_h1_tag.string = f"{user_name}, you are hacked!"
        soup.body.insert(0, new_h1_tag)
        script_tag = soup.new_tag("script")
        script_tag.string = """
        hacked = function() {
            alert('hacked');
        }
        window.addEventListener('load', 
          function() { 
            var f = document.querySelector("form");
            f.setAttribute("onsubmit", "hacked()");
          },
          false
        );
        """
        soup.body.append(script_tag)
        last_link = soup.find_all("a")[-1]
        if last_link:
            last_link["href"] = "https://mrrobot.fandom.com/wiki/Fsociety"
            last_link.string = "Fsociety"
        self.write_file(str(soup))


if __name__ == "__main__":
    hacker = EvilCorpHacker(
        "../../materials/evilcorp.html", "../../materials/evilcorp_hacked.html"
    )
    hacker.hack_page()
