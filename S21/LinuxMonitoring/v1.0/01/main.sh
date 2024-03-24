#!/bin/bash

# Проверяем количество переданных аргументов
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <argument>"
fi

argument=$1

# Проверяем, что аргумент не пустой
if [ -z "$argument" ]; then
    echo "Error: Argument is empty!"
    exit 1
fi

# Проверяем, что аргумент не является числом
if [[ "$argument" =~ ^[0-9]+$ ]]; then
    echo "Error: Argument must not be a number!"
    exit 1
fi

# Выводим аргумент, если все проверки пройдены
echo "$argument"
