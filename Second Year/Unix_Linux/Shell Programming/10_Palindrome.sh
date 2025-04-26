#!/bin/bash
read -p "Enter the string: " str
# Convert to lowercase
str=$( echo "$str" | tr '[:upper:]' '[:lower:]' ) 
# or
str=${str,,}
reverse_str=$(echo "$str" | rev) 
[ "$str" == "$reverse_str" ] && echo "$str is a palindrome" || echo "$str is not a palindrome" ]
# or 
if [ "$str" == "$reverse_str" ]; then
    echo "$str is a palindrome"
else
    echo "$str is not a palindrome"
fi

