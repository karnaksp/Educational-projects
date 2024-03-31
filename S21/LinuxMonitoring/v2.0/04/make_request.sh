##!/bin/bash

codes=("GET" "POST" "PUT" "PATCH" "DELETE")
echo ${codes[$((0 + $RANDOM % 5))]}
