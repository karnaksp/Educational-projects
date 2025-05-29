#!/bin/bash
if [ -z "$1" ]; then
  echo "Usage: $0 <file_extension>"
  exit 1
fi

find . -type f -name "*.$1" -delete