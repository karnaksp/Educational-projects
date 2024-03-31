#!/bin/bash

source color.sh
source suppl_functions.sh
source error_func.sh

nameBg=$1
nameText=$2
valueBg=$3
valueText=$4
argsCount=$#

checkInput $nameBg $nameText $valueBg $valueText
checkInputCh $nameBg $nameText $valueBg $valueText
nameBgColor=$(chooseBgColor $nameBg)
nameTextColor=$(chooseTextColor $nameText)
valueBgColor=$(chooseBgColor $valueBg)
valueTextColor=$(chooseTextColor $valueText)

get_network_info $nameTextColor $nameBgColor $valueTextColor $valueBgColor