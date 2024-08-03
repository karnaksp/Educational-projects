STYLE_RESULTS_FILE = style_results.txt
RATING_THRESHOLD = 8.0
SRC_DIR = .
REQUIREMENTS_FILE = ./requirements.txt

.PHONY: all clean Ex00 Ex01 Ex02 install_req get_req install_dep lint pep8 pylint sort-imports check_lint

all: cat clean Ex00 Ex01 Ex02

Ex00:
	@./cat.sh "Running tests for Ex00..." 10
	@cd Ex00 && coverage run -m unittest discover -v && \
	echo "" && ../cat.sh "Coverage report for Ex00..." 10 && \
	coverage report -m --include=energy.py

Ex01:
	@./cat.sh "Running tests for Ex01..." 10
	@cd Ex01 && coverage run -m unittest discover -v && \
	echo "" && ../cat.sh "Coverage report for Ex01..." 10 && \
	coverage report -m --include=personality.py

Ex02:
	@./cat.sh "Running Ex02..." 10
	@cd Ex02 && python3 main.py

cat:
	@chmod +x cat.sh

clean:
	@./cat.sh "Cleaning up..." 10
	@find . -type d -name '__pycache__' -exec rm -rf {} +
	@find . -type d -name 'htmlcov' -exec rm -rf {} +
	@find . -type d -name '.pytest_cache' -exec rm -rf {} +
	@rm -rf */.coverage */*.log
	@rm -rf */output.txt
	@rm -f *.txt ../materials/evilcorp_hacked.html ../materials/deploy.yml

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
	autopep8 --in-place --recursive --aggressive */*.py > $(STYLE_RESULTS_FILE); \
	isort . > $(STYLE_RESULTS_FILE); \
	pylint --disable=c-extension-no-member --fail-under=9.0 --output-format=colorized */*.py

run_in_docker:
	docker build -t karnaksp_day0 .
	docker run --rm -it karnaksp_day0 /bin/bash
