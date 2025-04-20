#!/bin/bash
read -p "Enter first number: " num1
read -p "Enter second number: " num2
read -p "Enter an operator (+, -, *, /): " operator
case $operator in
    +)
        result=$((num1 + num2))
        echo "$num1 + $num2 = $result"
        ;;
    -)
        result=$((num1 - num2))
        echo "$num1 - $num2 = $result"
        ;;
    /*)
        result=$((num1 * num2))
        echo "$num1 * $num2 = $result"
        ;;
    /)
        if [ $num2 -ne 0 ]; then
            result=$((num1 / num2))
            echo "$num1 / $num2 = $result"
        else
            echo "Error: Division by zero is not allowed."
        fi
        ;;
    *)
        echo "Error: Invalid operator. Please use +, -, *, or /."
        ;;
esac