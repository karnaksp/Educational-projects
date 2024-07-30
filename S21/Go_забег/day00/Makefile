STYLE_RESULTS_FILE = style_results.txt
RATING_THRESHOLD = 9.0
SRC_DIR = .
REQUIREMENTS_FILE = ./requirements.txt

.PHONY: all clean Ex00

all: gopher clean Ex00

Ex00:
	@./gopher.sh "Running tests for Ex00..." 10
	@cd Ex00 && go mod init day0 && go build -o day0 && bash run_test.sh


gopher:
	@chmod +x gopher.sh

clean:
	@./gopher.sh "Cleaning up..." 10
	@rm -rf */day0 */*.txt */*.mod

run_in_docker:
	docker build -t karnaksp_day0 .
	docker run --rm -it karnaksp_day0 /bin/bash
