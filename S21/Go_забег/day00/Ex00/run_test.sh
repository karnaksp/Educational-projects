#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

run_test() {
    input_file=$1
    expected_file=$2

    cat "$input_file" | ./day0 > output.txt 2>&1

    if diff -q output.txt "$expected_file" > /dev/null; then
        echo -e "${GREEN}Test with $input_file passed.${NC}"
    else
        echo -e "${RED}Test with $input_file failed.${NC}"
        echo "Expected:"
        cat "$expected_file"
        echo "Got:"
        cat output.txt
    fi
}

tests=(
    "../tests/input/1.txt ../tests/output/1.txt"
    "../tests/input/2.txt ../tests/output/2.txt"
    "../tests/input/3.txt ../tests/output/3.txt"
    "../tests/input/4.txt ../tests/output/4.txt"
    "../tests/input/invalid.txt ../tests/output/invalid.txt"
    "../tests/input/no_dir.txt ../tests/output/no_dir.txt"
)

for test in "${tests[@]}"; do
    run_test $test
done
