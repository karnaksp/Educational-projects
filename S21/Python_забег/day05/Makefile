RATING_THRESHOLD = 9.0
SRC_DIR = .
REQUIREMENTS_FILE = ./requirements.txt

PAGE_LIMIT = 10
NEO4J_URI = bolt://neo4j:7687
NEO4J_USER = neo4j
NEO4J_PASSWORD = assassass

.PHONY: all clean Ex00 Ex01 Ex02 install_req get_req install_dep lint pep8 pylint sort-imports check_lint

all: cat clean Ex00 Ex02

Ex00:
	@./cat.sh "Running Ex00 with limit $(PAGE_LIMIT) pages..." 10
	@cd Ex00 && python3 cache_wiki.py -p 'Babangida' -m $(PAGE_LIMIT)

Ex01:
	@./cat.sh "Running Ex01..." 10
	@cd Ex01 && python3 shortest_path.py -v --from 'Babangida' --to 'Xiamen' --non-directed

Ex02:
	@./cat.sh "Running Ex02..." 10
	@cd Ex02 && python3 render_graph.py WIKI_FILE wiki_graph.png --html-output wiki_graph.html

cat:
	@chmod +x cat.sh

clean:
	@./cat.sh "Cleaning up..." 10
	@sudo find . -type d -name '__pycache__' -exec rm -rf {} +
	@sudo find . -type d -name 'htmlcov' -exec rm -rf {} +
	@sudo find . -type d -name '.pytest_cache' -exec rm -rf {} +
	@sudo find . -type d -name 'cache_directory' -exec rm -rf {} +
	@sudo rm -rf */.coverage */*.log */*.html */*.png
	@sudo rm -rf */output.txt */*.json neo4j_data
	@sudo rm -f *.txt ../materials/evilcorp_hacked.html ../materials/deploy.yml

get_req:
	@./cat.sh "Get requirements for all python files..." 10
	@pipreqs $(SRC_DIR) --force --savepath $(REQUIREMENTS_FILE) > /dev/null 2>&1
	@sort -u $(REQUIREMENTS_FILE) > $(REQUIREMENTS_FILE).tmp
	@mv $(REQUIREMENTS_FILE).tmp $(REQUIREMENTS_FILE)
	@sed -i 's/==.*//' $(REQUIREMENTS_FILE)

install_dep:
	# curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
	# python3 get-pip.py
	pip install pipreqs isort pylint autopep8 pytest-cov

install_req: get_req
	pip install -r $(REQUIREMENTS_FILE)


check_lint:
	autopep8 --in-place --recursive --aggressive */*.py; \
	isort .; \
	pylint --disable=c-extension-no-member --fail-under=$(RATING_THRESHOLD) --output-format=colorized */*.py

build_in_docker:
	docker compose up -d --build

run_in_docker:
	docker compose run app

docker_up: build_in_docker run_in_docker

query:
	@./cat.sh "Running query on Neo4j..." 10
	@docker exec -it neo4j cypher-shell \
		--uri $(NEO4J_URI) \
		--username $(NEO4J_USER) \
		--password $(NEO4J_PASSWORD) \
		"MATCH (n) RETURN n LIMIT 10;"