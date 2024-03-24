#!/bin/bash

source error_func.sh
source suppl_functions.sh

inputDirectory=$1
argsCount=$#
scriptStart=$(date +%s.%N)

checkInput $inputDirectory
printFolderInfo $inputDirectory

scriptEnd=$(date +%s.%N)
scriptExeTime=$(echo "$scriptEnd - $scriptStart" | bc -l)
printf "\nScript execution time (in seconds) = %.1f\n" $scriptExeTime
