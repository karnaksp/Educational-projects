#!/bin/bash

err='Error:'
errWrongDir="$err No such directory! [$inputDirectory]"
errWrongFormatDir="$err Directory name should end with '/' character!"
errFewArgs="$err Less than 1 argument!"
errManyArgs="$err More than 1 argument!"

function isLessArgs {
  if [ $argsCount -lt 1 ]
  then
    echo $errFewArgs
    exit 1
  fi  
}

function isMoreArgs {
  if [ $argsCount -gt 1 ]
  then
    echo $errManyArgs
    exit 1
  fi  
}

function isCorrectFormatDir {
  if ! echo $1 | grep -qE ".*/$"
  then
    echo $errWrongFormatDir
    exit 1
  fi
}

function isCorrectDir {
  if ! [ -d $1 ]
  then
    echo $errWrongDir
    exit 1
  fi
}

function checkInput {
  isLessArgs
  isMoreArgs
  isCorrectFormatDir $1
  isCorrectDir $1
}