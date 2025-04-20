#!/bin/bash
echo "Choose an option:"
echo "1. List files"
echo "2. Display system info"
read -p "Enter your choice (1 or 2): " choice
case $choice in 
    1)
        echo "Listing files in the current directory:"
        ls -l
        ;;
    2)
        echo "Displaying system information:"
        uname -a
        ;;
    *)
        echo "Invalid choice. Please enter 1 or 2."
        ;;
esac