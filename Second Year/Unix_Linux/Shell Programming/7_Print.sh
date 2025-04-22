#!/bin/bash
read -p "Enter first number: " num1
read -p "Enter last number: " num2

for ((i=num1; i<=num2; i++)) do
    echo $i
done