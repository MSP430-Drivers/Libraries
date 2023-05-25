#! /bin/bash
cd ..
if [ -d "build/" ] 
then
    rm -r build
else 
    echo No build directory found
fi
