#!/bin/bash

ans='S'
input=()
read -r -a input
for val in ${input[@]}
do
	if [ $val -gt 1 ]
	then
		ans='F'
	fi
done

echo $ans
