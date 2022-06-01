#!/bin/sh

set -e

find ../data/lines -type f -name "*.in.txt" | sed "s/\\.in\\.txt\$//" | while read file; do
  echo "Processing $file.in.txt - 1024"
  "./$1" 1024 "$file.in.txt"
  echo "Processing $file.in.txt - 42"
  "./$1" 42 "$file.in.txt"
  echo "Processing $file.in.txt - 5"
  "./$1" 5 "$file.in.txt"
done
