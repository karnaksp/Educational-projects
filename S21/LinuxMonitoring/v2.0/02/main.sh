##!/bin/bash
source ./utils.sh

correct_input=$(bash ./input_check.sh $@)
if ! [[ $correct_input -eq 1 ]]; then
    exit 0
fi

start=$(date +%s%N)

echo "NEW SESSION $(date +"%F %T")" >> gen.log
if ! [ -f 1Mb_shit ]; then
    bash ./create_1Mb_shit.sh > 1Mb_shit
fi

find / -type d 2>/dev/null | grep -v -e"/bin/" -e"/sbin/" > all_dirs
dir_count=$(cat all_dirs | wc -l)

file_letters=${2%.*}
file_size=${3%Mb}
extension=.${2#*.}
if [[ $(echo $2 | tr -cd '.' | wc -c) -eq 0 ]]; then
    extension=""
fi
mem_flag=$(memStop)

while [[ $mem_flag -eq 0 ]]; do
    target=$(sed -n "$((1 + $RANDOM % $dir_count))"p all_dirs)
    folder=$1
    while [ -d "$target/$folder" ]; do
        folder=$(nameGen $folder)
    done
    if mkdir "$target/$folder" 2>/dev/null; then
        file_number=$(($RANDOM % 100)); i=0
        while [[ i -lt $file_number && $mem_flag -eq 0 ]]; do
            filename=$file_letters
            while [[ -f "$target/$folder/$filename$date$extension" || ${#filename} -lt 5 ]]; do
                filename=$(nameGen $filename)
            done
            filepath="$target/$folder/$filename$date$extension"
            if touch $filepath 2>/dev/null; then
                echo "CREATED $(date +"%F %T") $filepath $file_size Mb" >> gen.log
                for (( k = 0 ; k < $file_size ; k++ )); do
                    echo -n $(cat 1Mb_shit) 2>/dev/null >> $filepath
                done
            else
                rm -rf $filepath 2>/dev/null
            fi
            i=$[ $i + 1 ]
            mem_flag=$(memStop)
        done
    fi
    mem_flag=$(memStop)
done

end=$(date +%s%N)

echo "END OF SESSION $(date +"%F %T")" >> gen.log
echo "Script execution time (in seconds) = \
$(echo "scale=2;x=$(( $end - $start ))/1000000000; if(x<1) print 0; x" | bc)" >> gen.log

echo "Your PC is officially infected!"
echo "See details in gen.log"
