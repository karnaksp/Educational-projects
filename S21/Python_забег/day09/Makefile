STYLE_RESULTS_FILE = style_results.txt
RATING_THRESHOLD = 8.0
SRC_DIR = .
REQUIREMENTS_FILE = ./requirements.txt

.PHONY: all clean Ex00 Ex01 Ex02 clean check_lint

all: cat Ex00 Ex01 Ex02

activate_venv: 
	@python -m venv myenv
	@bash -c "source myenv/bin/activate && pip install -r $(REQUIREMENTS_FILE) >> log.txt 2>&1"

Ex00: clean activate_venv
	@./cat.sh "Build and test calculator for int..." 10
	@bash -c "source myenv/bin/activate && cd Ex00 && \
	sudo chmod -R u+w . && python setup.py build >> log.txt 2>&1 && \
	python setup.py install >> log.txt 2>&1 && \
	python tests/test_int_calculator.py \
	&& cd .. && $(MAKE) --no-print-directory clean && cd Ex00"
	@./cat.sh "Build and test calculator for float..." 10
	@bash -c "source myenv/bin/activate && cd Ex00 && \
	sudo chmod -R u+w . && python setup_float.py build >> log.txt 2>&1 && \
	python setup_float.py install >> log.txt 2>&1 && \
	python tests/test_float_calculator.py"

Ex01: clean activate_venv
	@./cat.sh "Run Ex01..." 10
	@bash -c "source myenv/bin/activate && cd Ex01 && \
	python -m unittest test.py"

Ex02: clean activate_venv
	@./cat.sh "Run Ex02..." 10
	@bash -c "source myenv/bin/activate && cd Ex02 && \
	python setup.py build_ext --inplace >> log.txt 2>&1 && python test_mul_perf.py"

cat:
	@chmod +x cat.sh

clean:
	@./cat.sh "Cleaning up..." 10
	@rm -rf Ex00/CalculatorModule.egg-info Ex00/build Ex00/dist
	@rm -rf Ex01/__pycache__ Ex02/build
	@rm -f log.txt Ex00/log.txt Ex02/log.txt */*.png 
	@rm -f Ex02/*.so Ex02/multiply.c

check_lint:
	autopep8 --in-place --recursive --aggressive */*.py > $(STYLE_RESULTS_FILE); \
	isort . > $(STYLE_RESULTS_FILE); \
	pylint --disable=c-extension-no-member --fail-under=9.0 --output-format=colorized */*.py

run_in_docker:
	docker build -t karnaksp_day .
	docker run --rm -it karnaksp_day /bin/bash
