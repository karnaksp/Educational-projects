#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

run_test() {
    input_file=$1
    expected_file=$2
    num_lines=$3
    coverage run --append blocks.py $num_lines < $input_file > output.txt
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
    "tests/input/test_input_1.txt tests/expected/expected_output_1.txt 3"
    "tests/input/test_input_2.txt tests/expected/expected_output_2.txt 3"
    "tests/input/test_input_3.txt tests/expected/expected_output_3.txt 3"
    "tests/input/test_input_4.txt tests/expected/expected_output_4.txt 4"
    "tests/input/test_input_5.txt tests/expected/expected_output_5.txt "
    "tests/input/test_input_6.txt tests/expected/expected_output_6.txt i"
)

coverage erase

for test in "${tests[@]}"; do
    run_test $test
done

