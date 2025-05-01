#!/bin/bash
authenticate_user() {
    read -p "Enter the username: " username
    read -p "Enter the password: " password
    
    if [[ "$username" == "admin" && "$password" == "admin123" ]]; then
        echo "Authentication successful!"
        return 0
    else
        echo "Authentication failed!"
        return 1
    fi
}

authenticate_user