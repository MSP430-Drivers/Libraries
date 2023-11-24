#! /bin/bash

~/Tools/clang-format/clang-format -i ../lib/gpio/src/*.c
~/Tools/clang-format/clang-format -i ../lib/gpio/include/*.h
~/Tools/clang-format/clang-format -i ../lib/platform/include/*.h
~/Tools/clang-format/clang-format -i ../lib/platform/src/*.c
~/Tools/clang-format/clang-format -i ../lib/icu/include/*.h
~/Tools/clang-format/clang-format -i ../lib/icu/src/*.c
~/Tools/clang-format/clang-format -i ../lib/bcm/include/*.h
~/Tools/clang-format/clang-format -i ../lib/bcm/src/*.c
~/Tools/clang-format/clang-format -i ../lib/timer/include/*.h
~/Tools/clang-format/clang-format -i ../lib/timer/src/*.c
~/Tools/clang-format/clang-format -i ../lib/wdt/include/*.h
~/Tools/clang-format/clang-format -i ../lib/wdt/src/*.c
~/Tools/clang-format/clang-format -i ../examples/timer/*.c
