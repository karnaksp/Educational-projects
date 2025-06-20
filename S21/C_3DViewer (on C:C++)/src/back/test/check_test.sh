#!/bin/bash

clear
echo "###################################################################"
echo "#           LAUNCH TESTS CASES FOR PROJECT S21_3DViewer_v1.0      #"
echo "###################################################################"
echo
GCC=$1
FLAGS=$(echo $2)
LIBS_OS_CHECK=$(echo $3)
FLAG_GCOV=$4

cd back/test/ 
find . -name "*.check" | while read FILE
do
    echo "--------------------------------------------"
    filename=$(basename "$FILE" \.check)
    checkmk $filename.check > test_$filename.c
    $GCC $FLAGS $FLAG_GCOV -c test_$filename.c -o test_$filename.o
    cd back && for file in ../s21*.c; do
                    $GCC $FLAGS $FLAG_GCOV -c "$file" -o "${file%.c}.o"
                    mv "${file%.c}.o" test/"${file%.c}.o"
                done
    $GCC $FLAGS $FLAG_GCOV -o test_$filename test_$filename.o ../s21*.c $LIBS_OS_CHECK
    echo "TESTS CASES --> $filename:"
    ./test_$filename
    # echo
    # rm -f test_$filename
done
