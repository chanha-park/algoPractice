#!/bin/bash

declare -i n
declare -i front
declare -i back
declare -i size
declare -i flag
declare -i pop

read -r n

front=0
size=1001
que=()

back=0
while [ $back -lt $n ]
do
    que[$back]=$(( $back + 1 ))
    back=$(( $back + 1 ))
done

flag=1
while [ $front -ne $back ]
do
    pop=${que[$front]}
    front=$(( ($front + 1) % $size ))
    if [ $flag -eq 1 ]
    then
        echo -n "$pop "
    else
        que[$back]=$pop
        back=$(( ($back + 1) % $size ))
    fi
    flag=$(( 1 - $flag ))
done
