#! /bin/bash

# Verificar si se proporcionó un argumento
if [ $# -eq 0 ]; then
    echo "Type packet to compile"
    exit 1
fi


packet=$1

cd ..

if [ ! -d "lib/$packet" ]
then
    echo "No valid packet"
    exit 1
fi

echo "Cleaning $packet packet"

cd lib/$packet

if [ -d "build/" ] 
then
    rm -r build
else 
    echo No build directory found
fi
