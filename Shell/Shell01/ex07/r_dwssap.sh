#!/bin/bash
cat /etc/passwd | grep -v '#' | awk 'NR%2==0' | awk -F : '{ print $1 }'| rev | sort -r | awk 'NR >= ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | awk '{print $0","}' | tr '\n' ' ' | sed 's/. $/./' | tr -d '\n'
