#!/bin/bash

read -p "Enter the file name: " filename

function compress_file {
    tar -czvf "$1".tar.gz "$1"
    echo "File '$1' has been compressed."
}

function decompress_file {
    tar -xzvf "$1"
    echo "File '$1' has been decompressed."
}

if [ -f "$filename" ]; then
    read -p "Do you want to compress or decompress the file? (c/d): " action
    case $action in
        c|C)
            compress_file "$filename"
            ;;
        d|D)
            decompress_file "$filename"
            ;;
        *)
            echo "Invalid option. Please enter 'c' to compress or 'd' to decompress."
            ;;
    esac
else
    echo "File '$filename' does not exist."
fi
