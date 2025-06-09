#!/bin/bash
for i in /etc/consul.d/*.json; do
    if [[ ! $i =~ $(hostname).json ]]; then
                rm -f $i
        fi
done
