#!/bin/bash

red='\033[0;31m'
green='\033[0;32m'
reset='\033[0m'

root=$(pwd)

dirs=(app00_BusinessRetail app01_Health app02_VideoLibrary)


echo "Creatig builds...\n"

for dir in "${dirs[@]}"
do
	cd "$root/$dir" || { echo "Failed to enter directory $dir"; continue; }
	cd build || { echo "Failed to enter $dir/build"; continue; }
	cmake -S . -B .
	cmake --build .
done


echo "\n${green}Done.\n"

echo "3${reset}   Applications created.\n${green}1: ./bank ${reset} inside app00_BusinessRetail\n${green}2: ./health ${reset}inside app01_Health\n${green}3: ./library ${reset}inside app02_VideoLibrary."
echo "\n"
