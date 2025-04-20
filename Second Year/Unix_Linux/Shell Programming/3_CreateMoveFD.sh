#!/bin/bash
read -p "Enter file to move:" file
read -p "Enter directory to create to:" dir
if [ -e "$file" ]; then
    echo "File exists."
    mkdir -p "$dir"
    mv "$file" "$dir/"
    echo "File moved to $dir"
else
    echo "File does not exist."
    exit 1
fi
