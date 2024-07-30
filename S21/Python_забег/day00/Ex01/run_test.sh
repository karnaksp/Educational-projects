#!/bin/sh

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

PROJECT_ROOT=$(dirname "$0")

run_test() {
    pytest --cov=. --cov-report=term-missing --cov-report=html > result.log 2>&1

    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Tests passed.${NC}"
    else
        echo -e "${RED}Tests failed.${NC}"
        exit 1
    fi
}

run_test
