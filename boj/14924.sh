#!/bin/bash

declare -i speed
declare -i fly
declare -i distance
read -r speed fly distance

echo $(( fly * distance / (2 * speed) ))
