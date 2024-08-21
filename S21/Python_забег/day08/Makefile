STYLE_RESULTS_FILE = style_results.txt
RATING_THRESHOLD = 8.0
SRC_DIR = .
REQUIREMENTS_FILE = ./requirements.txt

.PHONY: all clean Ex00 Ex01 Ex02 install_req install_dep check_lint

all: cat clean Ex00 Ex01 Ex02

create_venv:
	@python -m venv venv
	@bash -c "source venv/bin/activate && \
	pip install -r requirements.txt"

Ex00:
	@./cat.sh "Start fight with John, Neo..." 10
	@cd Ex00 && python fight.py
	@./cat.sh "Start fight whith many Johns, Neo..." 10
	@cd Ex00 && python fightmany.py

Ex01: create_venv
	@$(MAKE) --no-print-directory start_server

Ex02: create_venv
	@$(MAKE) --no-print-directory start_cashe_server

run_client:
	@./cat.sh "Run client..." 10
	@bash -c "source venv/bin/activate && cd Ex01 && python crawl.py $(URLS)"

start_server:
	@./cat.sh "Start server..." 10
	@bash -c "source venv/bin/activate && cd Ex01 && python server.py"

start_cashe_server:
	@./cat.sh "Start cashe server..." 10
	@bash -c "source venv/bin/activate && cd Ex02 && python server.py"

cat:
	@chmod +x cat.sh

clean:
	@./cat.sh "Cleaning up..." 10
	@find . -type d -name '__pycache__' -exec rm -rf {} +
	@find . -type d -name 'htmlcov' -exec rm -rf {} +
	@find . -type d -name '.pytest_cache' -exec rm -rf {} +
	@rm -rf */.coverage */*.log venv
	@rm -rf $(BUILDDIR)/doctrees $(BUILDDIR)/html

install_dep:
	# curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
	# python3 get-pip.py
	pip install pipreqs isort pylint autopep8

install_req:
	pip install -r $(REQUIREMENTS_FILE)


check_lint:
	autopep8 --in-place --recursive --aggressive */*.py \
	isort . > $(STYLE_RESULTS_FILE); \
	pylint --disable=c-extension-no-member --fail-under=9.0 --output-format=colorized */*.py

run_in_docker:
	docker build -t karnaksp_day .
	docker run --rm -it karnaksp_day /bin/bash

URLS = \
	http://example.com \
	http://anotherexample.com \
	http://nonexistentwebsite.xyz \
	https://google.com \
	http://badurl.abc \
	https://openai.com \
	http://localhost:1234 \
	http://invalid-url.com \
	https://github.com \
	http://nonexistent-domain-123.com \
	https://stackoverflow.com \
	http://thispagedoesnotexist.com \
	https://python.org \
	http://404page.com \
	https://yahoo.com \
	http://unknownsite.unknown \
	https://wikipedia.org \
	http://another-fake-url.xyz \
	https://bing.com \
	http://badlink.bad \
	https://duckduckgo.com \
	http://unreachablewebsite.xyz \
	https://reddit.com \
	http://fakepage.fake \
	https://news.ycombinator.com \
	http://unknownserver.unknown