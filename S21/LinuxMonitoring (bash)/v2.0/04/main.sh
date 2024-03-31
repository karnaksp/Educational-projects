##!/bin/bash

rm -rf ./logs
mkdir ./logs

for ((i = 0 ; i < 5 ; i++)); do
    date=$(date --date="today -$i day" "+%d-%m-%Y")
    bash generate_log.sh $i >> ./logs/nginx_$date.log
done
