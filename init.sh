#!/bin/bash

red='\033[0;31m'
green='\033[0;32m'
reset='\033[0m'


##sorry for not puting this in Cmake ......... ............ for app02 cube game
function is_package_installed() {
    dpkg-query -W -f='${Status}' "$1" 2>/dev/null | grep -q "install ok installed"
}

# Install packages if not already installed
function install_packages() {
    local packages=("$@")
    local missing_packages=()

    for package in "${packages[@]}"; do
        if ! is_package_installed "$package"; then
            missing_packages+=("$package")
        fi
    done

    if [[ ${#missing_packages[@]} -gt 0 ]]; then
        echo "Installing missing packages: ${missing_packages[@]}"
        sudo apt-get update
        sudo apt-get install "${missing_packages[@]}"
    else
        echo "All required packages are already installed."
    fi
}





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



apt-get install gcc make xorg libxext-dev libbsd-dev 