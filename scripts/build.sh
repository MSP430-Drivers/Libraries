#!/bin/bash

# Function to check if an argument is provided
check_arguments() {
    if [ $# -eq 0 ]; then
        echo "write a valid packet to compile"
        exit 1
    fi
}

# Function to check if the packet is valid
check_valid_packet() {
    if [ ! -d "$type/$packet" ]; then
        echo "No valid packet"
        exit 1
    fi
}

# Function to compile the packet
compile_packet() {
    echo "Compiling $packet $type"

    cd $type/$packet
    
    if [ ! -d "build/" ]; then
        mkdir build
    fi
    
    cd build
    export CC=~/Tools/msp430-gcc/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-gcc
    export CXX=~/Tools/msp430-gcc/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-g++
    cmake ..
    make
}

# Function to compile the library
compile_library() {
    if [ ! -d "build/" ]; then
       mkdir build
    fi
    
    cd build
    export CC=~/Tools/msp430-gcc/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-gcc
    export CXX=~/Tools/msp430-gcc/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-g++
    cmake ..
    make
}

# Navigate to the parent directory
cd ..

# Check for arguments
check_arguments "$@"

type=$1
packet=$2

# Check if type is "library" and compile accordingly
if [ "$type" = "library" ]; then
    compile_library
else
    # Check if the packet is valid
    check_valid_packet
    # Compile the packet
    compile_packet
fi
