cmake_minimum_required(VERSION 3.22)

project(msp430_example)

set(CMAKE_EXECUTABLE_SUFFIX .elf)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER ${CMAKE_SOURCE_DIR}/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-gcc)
set(CMAKE_C_FLAGS "-mmcu=msp430g2553")
set(CMAKE_EXE_LINKER_FLAGS "-T ../lnk_msp430g2553.cmd")

add_executable(library src/library.c)