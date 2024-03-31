##!/bin/bash
source ./utils.sh

correct_input=$(bash ./input_check.sh $@)
if ! [[ $correct_input -eq 1 ]]; then
    exit 0
fi

folder_letters=$3
file_letters=${5%.*}
file_size=${6%kb}
extension=.${5#*.}
if [[ $(echo $5 | tr -cd '.' | wc -c) -eq 0 ]]; then
    extension=""
fi

i=0
mem_left=$(memLeft)

while [[ $i -lt $2 && $mem_left -gt 1 ]]; do  # FOLDER cycle BEGINING
    folder=$folder_letters
    while [ -d "$1/$folder" ]; do
        folder=$(nameGen $folder)
    done
    mkdir "$1/$folder"
    j=0
    while [[ $j -lt $4 && $mem_left -gt 1 ]]; do  # FILE cycle BEGINING
        filename=$file_letters
        while [[ -f "$1/$folder/$filename$date$extension" || ${#filename} -lt 4 ]]; do
            filename=$(nameGen $filename)
        done
        filepath="$1/$folder/$filename$date$extension"
        touch $filepath
        for (( k = 0 ; k < $file_size ; k++ )); do
            echo -n "$chunk" >> $filepath
        done
        j=$[ $j + 1 ]
        echo "$(date +"%F %T") $filepath $file_size kb" >> ./gen.log
        mem_left=$(memLeft)
    done  # FILE cycle END
    i=$[ $i + 1 ]
    mem_left=$(memLeft)
done  # FOLDER cycle END

if [[ i -eq $2 ]]; then
    echo "Generation is done successfully."
else
    echo "There is only 1GB space left on /. Generation has stopped."
fi
echo "See details in gen.log"
