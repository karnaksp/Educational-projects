##!/bin/bash

if [ $# -eq 6 ]; then
    if ! [[ -d $1 ]]; then
        >&2 echo "Argument 1: Directory does not exist."
    elif ! [[ $2 =~ ^[0-9]+$ && $4 =~ ^[0-9]+$ ]]; then
        >&2 echo "Argument 2 and argument 4 must be numbers."
    elif ! [[ ${#3} -le 7 && $3 =~ ^[a-zA-Z]+$ ]]; then
        >&2 echo "Argument 3: No more than 7 english letters."
    elif ! [[ ${6%kb} =~ ^[0-9]+$ && ${6%kb} -le 100 ]]; then
        >&2 echo "Argument 6: Format is [number]kb. Number is not more than 100."
    elif [[ $(echo $5 | tr -cd '.' | wc -c) -gt 1 ]]; then
        >&2 echo "Argument 5: Incorrect filename."
    else
        if [[ $(echo $5 | tr -cd '.' | wc -c) -eq 0 ]]; then
            filename=$5
            extension=""
        else
            filename=${5%.*}
            extension=${5#*.}
        fi
        if ! [[ ${#filename} -le 7 && $filename =~ ^[a-zA-Z]+$ ]]; then
            >&2 echo "Argument 5: Filename is no more than 7 english letters."
        elif ! [[ -z "$extension" ]] && ! \
        [[ ${#extension} -le 3 && ${#extension} -ge 1 && $extension =~ ^[a-zA-Z]+$ ]]; then
            >&2 echo "Argument 5: Incorrect extension."
        else
            echo 1
        fi

    fi
else
    >&2 echo "Please give 6 arguments."
fi
