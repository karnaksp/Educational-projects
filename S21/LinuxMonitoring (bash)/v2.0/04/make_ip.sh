##!/bin/bash

ip=''
variant=$((1 + $RANDOM % 3))

if [ $variant -eq 1 ]; then  # 10.0.0.0 - 10.255.255.255
    ip="10.$((0 + $RANDOM % 256)).$((0 + $RANDOM % 256)).$((0 + $RANDOM % 256))"
elif [ $variant -eq 2 ]; then  # 172.16.0.0 - 172.31.255.255
    ip="172.$((16 + $RANDOM % 16)).$((0 + $RANDOM % 256)).$((0 + $RANDOM % 256))"
elif [ $variant -eq 3 ]; then  # 192.168.0.0 до 192.168.255.255
    ip="192.168.$((0 + $RANDOM % 256)).$((0 + $RANDOM % 256))"
fi

echo $ip
