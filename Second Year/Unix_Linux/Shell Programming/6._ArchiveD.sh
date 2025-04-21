#!/bin/bash

read -p "Enter the file name: " file_name
read -p "Enter days: " days

if [ -f "$file_name" ] && [ "$(find "$file_name" -type f -mtime +$days)" ]; then
    tar -czvf "${file_name}.tar.gz" "$file_name"
    echo "The file $file_name is older than $days days and has been archived."
else
    echo "The file $file_name is not older than $days days."
fi