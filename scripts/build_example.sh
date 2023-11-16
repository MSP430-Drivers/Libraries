#! /bin/bash

# Verificar si se proporcionó un argumento
if [ $# -eq 0 ]; then
    echo "Type packet to compile"
    exit 1
fi

packet=$1

cd ..

if [ ! -d "examples/$packet" ]
then
    echo "No valid packet"
    exit 1
fi

echo "Compiling $packet packet"

cd examples/$packet

if [ ! -d "build/" ] 
then
    mkdir build
fi

cd build
export CC=~/Tools/msp430-gcc/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-gcc
export CXX=~/Tools/msp430-gcc/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-g++
cmake ..
make