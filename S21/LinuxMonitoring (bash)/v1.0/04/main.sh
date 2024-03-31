#!/bin/bash

source ../03/color.sh
source ../03/suppl_functions.sh

source suppl_functions.sh

nameBg=$(awk -F'=' 'NR==1{if ($2 != "") {print $2} else {print "default"}}' color.conf)
nameText=$(awk -F'=' 'NR==2{if ($2 != "") {print $2} else {print "default"}}' color.conf)
valueBg=$(awk -F'=' 'NR==3{if ($2 != "") {print $2} else {print "default"}}' color.conf)
valueText=$(awk -F'=' 'NR==4{if ($2 != "") {print $2} else {print "default"}}' color.conf)

nameBgDefault=6
nameTextDefault=1
valueBgDefault=6
valueTextDefault=5

nameBgDefaultFlag=0
nameTextDefaultFlag=0
valueBgDefaultFlag=0
valueTextDefaultFlag=0

processInput
checkInput $nameBg $nameText $valueBg $valueText
nameBgColor=$(chooseBgColor $nameBg)
nameTextColor=$(chooseTextColor $nameText)
valueBgColor=$(chooseBgColor $valueBg)
valueTextColor=$(chooseTextColor $valueText)

get_network_info $nameTextColor $nameBgColor $valueTextColor $valueBgColor

printColorInfo $nameBg $nameText $valueBg $valueText