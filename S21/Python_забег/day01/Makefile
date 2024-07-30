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
	coverage report -m --include=purse.py

Ex01:
	@./cat.sh "Running tests for Ex01..." 10
	@cd Ex01 && coverage run -m unittest discover -v && \
	echo "" && ../cat.sh "Coverage report for Ex01..." 10 && \
	coverage report -m --include=split_booty.py

Ex02:
	@./cat.sh "Running tests for Ex02..." 10
	@cd Ex02 && coverage run -m unittest discover -v && \
	echo "" && ../cat.sh "Coverage report for Ex02..." 10 && \
	coverage report -m --include=decorator.py

cat:
	@chmod +x cat.sh

clean:
	@./cat.sh "Cleaning up..." 10
	@find . -type d -name '__pycache__' -exec rm -rf {} +
	@find . -type d -name 'htmlcov' -exec rm -rf {} +
	@find . -type d -name '.pytest_cache' -exec rm -rf {} +
	@rm -rf */.coverage */*.log
	@rm -rf */output.txt
	@rm -f *.txt 

get_req:
	@./cat.sh "Get requirements for all python files..." 10
	@pipreqs $(SRC_DIR) --force --savepath $(REQUIREMENTS_FILE) > /dev/null 2>&1
	@sort -u $(REQUIREMENTS_FILE) > $(REQUIREMENTS_FILE).tmp
	@mv $(REQUIREMENTS_FILE).tmp $(REQUIREMENTS_FILE)
	@sed -i 's/==.*//' $(REQUIREMENTS_FILE)

install_dep:
	pip install pipreqs isort pylint autopep8 pytest-cov

install_req:
	pip install -r $(REQUIREMENTS_FILE)


check_lint:
	autopep8 --in-place --recursive --aggressive */*.py > $(STYLE_RESULTS_FILE); \
	isort . > $(STYLE_RESULTS_FILE); \
	pylint --disable=c-extension-no-member --fail-under=9.0 --output-format=colorized */*.py
	rating=$$(sed -n 's/.*Your code has been rated at \([0-9]*\.[0-9]*\)\/10.*/\1/p' $(STYLE_RESULTS_FILE)); \
	if echo "$$rating > $(RATING_THRESHOLD)" | bc -l | grep -q '^1$$'; then  \
		./cat.sh "\033[0;32mSTYLE_TESTS PASSED with $$rating: look $(STYLE_RESULTS_FILE)\033[0m" 10; \
	else \
		./cat.sh "\033[0;31mSTYLE_TESTS FAILED with $$rating: look $(STYLE_RESULTS_FILE)\033[0m" 10; \
	fi

run_in_docker:
	docker build -t karnaksp_day0 .
	docker run --rm -it karnaksp_day0 /bin/bash
