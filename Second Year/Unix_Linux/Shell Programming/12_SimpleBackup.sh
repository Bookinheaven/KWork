#!/bin/bash

function backup {
    source_dir="$1"
    backup_dir="$2"
    # read -p "Enter the directory to backup: " source_dir
    # read -p "Enter the backup directory: " backup_dir

    if [ ! -d "$source_dir" ]; then
        echo "Error: Source directory $source_dir does not exist."
        exit 1
    fi

    timestamp=$(date +"%Y%m%d_%H%M%S")
    backup_file="$backup_dir/backup_$timestamp.tar.gz"

    mkdir -p "$backup_dir" || {
        echo "Error: Failed to create backup directory."
        exit 1
    }

    echo "Creating backup of $source_dir..."
    tar -czf "$backup_file" -C "$(dirname "$source_dir")" "$(basename "$source_dir")"

    if [ $? -eq 0 ]; then
        echo "Backup completed successfully."
        echo "Backup file: $backup_file"
    else
        echo "Backup failed."
        exit 1
    fi
}

if [ $# -eq 2 ]; then
    backup "$1" "$2"
else
    backup
fi

# For crontab -e
# 0 2 * * * /home/kali/Desktop/practice/ex2/10.sh /home/kali/Desktop/practice/ex2/dat2.txt /home/kali/Desktop/practice/ex2/d2
# To check the cron jobs:
# crontab -l
# To remove the cron job:
# crontab -r