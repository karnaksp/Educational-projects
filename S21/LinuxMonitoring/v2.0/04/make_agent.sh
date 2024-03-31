##!/bin/bash

agent=("Mozilla" "Google Chrome" "Opera" "Safari" "Internet Explorer" "Microsoft Edge" "Crawler and bot" "Library and net tool")
echo ${agent[$((0 + $RANDOM % 8))]}
