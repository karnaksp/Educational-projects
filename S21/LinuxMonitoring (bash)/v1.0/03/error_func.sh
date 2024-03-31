#!/bin/bash

err='Error:'
errNumerical="$err Arguments non numeric!"
errDuplicate="$err Duplicate arguments!"
errRange="$err Arguments not in range of 1-6!"
errFewArgs="$err Less than 4 arguments!"
errManyArgs="$err More than 4 arguments!"

function isLessArgs {
  if [ $argsCount -lt 4 ]
  then
    echo $errFewArgs
    exit 1
  fi  
}

function isMoreArgs {
  if [ $argsCount -gt 4 ]
  then
    echo $errManyArgs
    exit 1
  fi  
}

function isArgsNumerical {
  if ! [[ $1 =~ ^[0-9]+$ && $2 =~ ^[0-9]+$ && $3 =~ ^[0-9]+$ && $4 =~ ^[0-9]+$ ]]
  then
    echo $errNumerical
    exit 1
  fi
}

function isArgsUnique {
  if [ $1 == $2 ] || [ $3 == $4 ]
  then
    echo $errDuplicate
    exit 1
  fi
}

function isArgsInRange {
  if ! [[ $1 =~ ^[1-6]+$ && $2 =~ ^[1-6]+$ && $3 =~ ^[1-6]+$ && $4 =~ ^[1-6]+$ ]]
  then
    echo $errRange
    exit 1
  fi
}

function checkInput {
  isArgsNumerical $1 $2 $3 $4
  isArgsUnique $1 $2 $3 $4
  isArgsInRange $1 $2 $3 $4
}

function checkInputCh {
  isLessArgs
  isMoreArgs
}