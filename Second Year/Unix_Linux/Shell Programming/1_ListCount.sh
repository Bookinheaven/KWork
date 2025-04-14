#!/bin/bash

# Method 1
# echo "Enter the directory path:"
# read dir_path 

# Method 2
# echo "Enter the directory path:" dir_path=$1 

# Method 3
read -p "Enter the directory path: " dir_path

# Check if the directory exists
if [ ! -d "$dir_path" ]; then
    echo "Directory does not exist."
    exit 1
else
    echo "Directory exists."
    # Count the number of files and directories
    # Method 1 : Counts files in the current directory and subdirectories
    file_count=$(find "$dir_path" -type f | wc -l)
    # Method 2 : Only counts files in the current directory, not subdirectories
    # file_count=$(ls -1 "$dir_path" | wc -l) 
    echo "Number of files in $dir_path: $file_count"
fi
