#!/bin/bash

read -p "Enter the directory path: " dir_path
if [ -d "$dir_path" ]; then
    total_size=0
    file_count=0

    for file in "$dir_path"/*; do 
        if [ -f "$file" ]; then 
            file_size=$(stat -c %s "$file")
            total_size=$((total_size + file_size))
            file_count=$((file_count + 1))
        fi
    done
    echo "Total size of files in $dir_path: $total_size bytes"
    echo "Total number of files in $dir_path: $file_count"
else
    echo "Error: $dir_path is not a valid directory."
fi