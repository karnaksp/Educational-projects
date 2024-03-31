#!/bin/bash

function printMaxFolders {
  du -h -d 1 $1| sort -hr | head -n 6 >> tmp.txt

  dirOutput=$(cat -n tmp.txt)

  while IFS= read -r line; do
    list+=("$line")
  done <<< "$dirOutput"

  unset 'list[0]'

  count=1
  for item in "${list[@]}"; do
    filePath=$(echo "$item" | awk '{print $3}')
    size=$(echo "$item" | awk '{print $2}')
    echo "$count - $filePath, $size"
    ((count++))
  done
  rm -f tmp.txt
}

function printFilesInfo {
  configFiles=$(find $1 -type f -name '*.config' | wc -l)
  textFiles=$(find $1 -type f 2> /dev/null| grep .txt| wc -l)
  exeFiles=$(find $1 -type f -executable 2> /dev/null| wc -l)
  logFiles=$(ls -alR $1  2> /dev/null| grep .log| wc -l)
  archiveFiles=$(find $1 -type f 2> /dev/null| grep "[.tar|.zip|.gz|.tar.gz|.tar.bz2]" | wc -l)
  symbolicLinks=$(find $1 -type l 2> /dev/null| wc -l)

  echo "Number of:"
  echo "Configuration files (with the .conf extension) = $configFiles"
  echo "Text files = $textFiles"
  echo "Executable files = $exeFiles"
  echo "Log files (with the extension .log) = $logFiles"
  echo "Archive files = $archiveFiles"
  echo "Symbolic links = $symbolicLinks"
}

function printMaxFiles {
  find $1 -type f 2> /dev/null -printf '%p %s\n' | awk -F '.' '{print $0 " " $NF}' | sort -nrk2 | nl | numfmt --to=iec --field=3 | awk '{print $1" - "$2", "$3", "$4}' | column | head -10
}

function printMaxExe {
  find $1 -type f 2> /dev/null -executable -printf "%p %s " -exec md5sum {$4} \; | sort -nrk2 | nl |numfmt --to=iec --field=3 | awk '{print $1" - "$2", "$3", "$4}' | column | head -10
}

function printFolderInfo {
  totalFolders=$(( $(find $1 -type d | wc -l) - 1 ))
  totalFiles=$(find $1 -type f | wc -l)

  echo "Total number of folders (including all nested ones) = $totalFolders"
  echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
  printMaxFolders $1
  echo "Total number of files = $totalFiles"
  printFilesInfo $1
  echo "TOP 10 files of maximum size arranged in descending order (path, size and type):"
  printMaxFiles $1
  echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file)"
  printMaxExe $1
}