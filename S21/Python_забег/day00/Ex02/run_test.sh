#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

run_test() {
    input_file=$1
    expected_file=$2
    coverage run --append mfinder.py $args $input_file > output.txt 2>&1
    diff output.txt $expected_file > /dev/null

    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Test with $input_file passed.${NC}"
    else
        echo -e "${RED}Test with $input_file failed.${NC}"
        echo "Expected:"
        cat $expected_file
        echo "Got:"
        cat output.txt
    fi
}

tests=(
    "images/valid_pattern.txt images/expected_valid_pattern.txt"
    "images/invalid_pattern.txt images/expected_invalid_pattern.txt"
    "images/wrong_format.txt images/expected_wrong_format.txt"
    "images/non_existent_file.txt images/expected_file_read_error.txt"
    "images/m.txt images/expected_m.txt"
    "images/invalid_m.txt images/expected_invalid_m.txt"
)

coverage erase

for test in "${tests[@]}"; do
    run_test $test
done
