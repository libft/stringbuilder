#!/bin/sh

set -e

find ../data/lines -type f -name "*.in.txt" | sed "s/\\.in\\.txt\$//" | sort | while read file; do
  "./$1" 1024 < "$file.in.txt" | cmp -s "$file.out.txt" -
  "./$1" 42 < "$file.in.txt" | cmp -s "$file.out.txt" -
  "./$1" 5 < "$file.in.txt" | cmp -s "$file.out.txt" -
done
