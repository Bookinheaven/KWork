#!/bin/bash

echo -e "Size\tLast Modified\t\tFile"
echo "--------------------------------------------"

find . -type f -printf "%s\t%TY-%Tm-%Td %TH:%TM\t%p\n"