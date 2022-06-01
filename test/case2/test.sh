#!/bin/sh

set -e

find ../data/lines -type f -name "*.in.txt" | while read file; do
  "./$1" 1024 "$file"
  "./$1" 42 "$file"
  "./$1" 5 "$file"
  "./$1" 1 "$file"
done
