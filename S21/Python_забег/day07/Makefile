STYLE_RESULTS_FILE = style_results.txt
RATING_THRESHOLD = 9.0
SRC_DIR = .
REQUIREMENTS_FILE = ./requirements.txt

SPHINXOPTS    ?=
SPHINXBUILD   ?= sphinx-build
SOURCEDIR     = Ex02/source
BUILDDIR      = Ex02/build
VENV_DIR      = venv

.PHONY: all clean create_venv html Ex00 Ex01 install_req install_dep check_lint

all: cat clean

create_venv:
	@python -m venv venv
	@bash -c "source venv/bin/activate && \
	pip install -r requirements.txt"

Ex00: create_venv
	@./cat.sh "Simulate user behavior for Ex00..." 10
	@cd Ex00 && python simulate_user.py

Ex01: create_venv
	@./cat.sh "Running tests for Ex01..." 10
	@cd Ex01 && chmod +x run_test.sh && bash run_test.sh

html:
	@$(VENV_DIR)/bin/$(SPHINXBUILD) -M html $(SOURCEDIR) $(BUILDDIR) $(SPHINXOPTS)

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
