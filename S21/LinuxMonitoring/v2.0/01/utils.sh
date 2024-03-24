##!/bin/bash

function nameGen {
    i=$(($RANDOM % ${#1}))
    ch=$(echo $1 | cut -c $[ i+1 ])
    echo "${1:0:i}$ch${1:i}"
}

function memLeft {
    mem=($(df -BG / | grep "/"))
    mem_left=${mem[3]}
    echo ${mem_left%G}
}

chunk=""
for i in {1..1024}; do
    chunk=A$chunk
done

date=_$(date +"%d%m%y")
