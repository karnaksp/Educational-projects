#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

VENV_DIR="../venv"

run_test() {
    if [ -f "${VENV_DIR}/bin/activate" ]; then
        . "${VENV_DIR}/bin/activate"
    else
        echo -e "${RED}Virtual environment not found.${NC}"
        exit 1
    fi
    pytest --cov=. --cov-report=term-missing --cov-report=html
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Tests passed.${NC}"
    else
        echo -e "${RED}Tests failed.${NC}"
        exit 1
    fi
}

run_test
