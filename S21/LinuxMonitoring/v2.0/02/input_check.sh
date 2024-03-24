##!/bin/bash

allright=0
if [ $# -eq 3 ]; then
    if ! [[ ${#1} -le 7 && $1 =~ ^[a-zA-Z]+$ ]]; then
        >&2 echo "Argument 1 (folder name): No more than 7 english letters."
    elif ! [[ ${3%Mb} =~ ^[0-9]+$ && ${3%Mb} -le 100 ]]; then
        >&2 echo "Argument 3: Format is [number]Mb. Number is not more than 100."
    elif [[ $(echo $2 | tr -cd '.' | wc -c) -gt 1 ]]; then
        >&2 echo "Argument 2 (file name): Incorrect filename."
    else
        if [[ $(echo $2 | tr -cd '.' | wc -c) -eq 0 ]]; then
            filename=$2
            extension=""
        else
            filename=${2%.*}
            extension=${2#*.}
        fi
        if ! [[ ${#filename} -le 7 && $filename =~ ^[a-zA-Z]+$ ]]; then
            >&2 echo "Argument 2 (file name): Filename is no more than 7 english letters."
        elif ! [[ -z "$extension" ]] && ! \
        [[ ${#extension} -le 3 && ${#extension} -ge 1 && $extension =~ ^[a-zA-Z]+$ ]]; then
            >&2 echo "Argument 2 (file name): Incorrect extension."
        else
            allright=1
        fi
    fi
else
    >&2 echo "Please give 3 arguments."
fi
echo $allright
