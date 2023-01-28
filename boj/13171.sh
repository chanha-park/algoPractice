#!/bin/bash

read -r a
read -r x
tmp=1

MOD=1000000007

a=$(( a % MOD ))
while [ $x -gt 1 ]
do
	if [ $(( x & 1 )) -eq 1 ]
	then
		tmp=$(( (tmp * a) % MOD ))
	fi
	a=$(( (a * a) % MOD ))
	x=$(( x >> 1 ))
done

x=$(( (a * tmp) % MOD ))
echo $x
