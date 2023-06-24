#! /bin/bash

cd ..
if [ ! -d "documentation/" ] 
then
    mkdir documentation
fi

~/Tools/doxygen/doxygen-1.9.7/bin/doxygen config-doxygen.conf 2> documentation/doxygen.log