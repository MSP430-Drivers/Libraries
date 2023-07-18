#! /bin/bash

~/Tools/clang-format/clang-format -i ../lib/gpio/src/*.c
~/Tools/clang-format/clang-format -i ../lib/gpio/include/*.h
~/Tools/clang-format/clang-format -i ../lib/platform/include/*.h
~/Tools/clang-format/clang-format -i ../lib/platform/src/*.c
~/Tools/clang-format/clang-format -i ../lib/dio/include/*.h
~/Tools/clang-format/clang-format -i ../lib/dio/src/*.c