#!/bin/bash

source ../03/error_func.sh

function isDefault {
  if [ $1 -eq 1 ]
  then
    echo 'default'
  else
    echo "$2"
  fi
}

function processInput {
  if [ $nameBg == "default" ]
  then
    nameBg=$nameBgDefault
    nameBgDefaultFlag=1
  fi
  if [ $nameText == "default" ]
  then
    nameText=$nameTextDefault
    nameTextDefaultFlag=1
  fi
  if [ $valueBg == "default" ]
  then
    valueBg=$valueBgDefault
    valueBgDefaultFlag=1
  fi
  if [ $valueText == "default" ]
  then
    valueText=$valueTextDefault
    valueTextDefaultFlag=1
  fi
}

function getColorName {
  local color
  case "$1" in
      1) color="white";;
      2) color="red";;
      3) color="green";;
      4) color="blue";;
      5) color="purple";;
      6) color="black";;
  esac
  echo "$color"
}

function printColorInfo {
  echo
  echo "Column 1 background = $(isDefault $nameBgDefaultFlag $1) ($(getColorName $1))"
  echo "Column 1 font color = $(isDefault $nameTextDefaultFlag $2) ($(getColorName $2))"
  echo "Column 2 background = $(isDefault $valueBgDefaultFlag $3) ($(getColorName $3))"
  echo "Column 2 font color = $(isDefault $valueTextDefaultFlag $4) ($(getColorName $4))"
}
