STYLE_RESULTS_FILE = style_results.txt
RATING_THRESHOLD = 8.0
SRC_DIR = .
REQUIREMENTS_FILE = ./requirements.txt

.PHONY: all clean Ex00 Ex01 Ex02 install_req get_req install_dep lint pep8 pylint sort-imports check_lint

all: cat clean Ex00 Ex01 Ex02

start_server:
	@./cat.sh "Starting gRPC server..." 10
	@cd $${DIR} && python3 -m grpc_tools.protoc --python_out=. --pyi_out=. --grpc_python_out=. -I./ spaceship.proto && \
	python3 reporting_server.py & echo $$! > server.pid

run_client:
	@./cat.sh "Running client..." 10
	@cd $${DIR} && python3 reporting_client.py 0 0

stop_server:
	@./cat.sh "Stopping gRPC server..." 10
	@if [ -f server.pid ]; then \
		kill `cat server.pid` && rm server.pid; \
	else \
		echo "No server.pid file found. Nothing to stop."; \
	fi

Ex00:
	@DIR="Ex00" $(MAKE) --no-print-directory start_server
	@sleep 2
	@DIR="Ex00" $(MAKE) --no-print-directory run_client

Ex01:
	@DIR="Ex01" $(MAKE) --no-print-directory start_server
	@sleep 2
	@DIR="Ex01" $(MAKE) --no-print-directory run_client

Ex02:
	@DIR="Ex02" $(MAKE) --no-print-directory start_server
	@sleep 2
	@DIR="Ex02" $(MAKE) --no-print-directory run_client

cat:
	@chmod +x cat.sh

clean: stop_server
	@./cat.sh "Cleaning up..." 10
	@find . -type d -name '__pycache__' -exec rm -rf {} +
	@find . -type d -name 'htmlcov' -exec rm -rf {} +
	@find . -type d -name '.pytest_cache' -exec rm -rf {} +
	@rm -rf */.coverage */*.log
	@rm -rf */output.txt
	@rm -f *.txt ../materials/evilcorp_hacked.html ../materials/deploy.yml */spaceship_*.py */spaceship_*.pyi

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
