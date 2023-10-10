# Minimum required version of CMake
cmake_minimum_required(VERSION 3.22)

# Project name
project(msp430_example)

# Set msp-gcc for c files
set(CMAKE_C_COMPILER $ENV{HOME}/Tools/msp430-gcc/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-gcc)
set(CMAKE_CXX_COMPILER $ENV{HOME}/Tools/msp430-gcc/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-g++)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}_${PROJECT_VERSION_MINOR}_${PROJECT_VERSION_PATCH}")

# include_directories(lib/platform)

# Sources
set(SRC_DIR examples)

set(SOURCES
    ${SRC_DIR}/library.c
)

# Include directories
include_directories(examples)

# Compiler flags
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-mmcu=msp430g2553 -O2 -g -Wall -std=c11 -Wl,-Map=output.map")
set(CMAKE_CXX_FLAGS "-mmcu=msp430g2553 -O2 -g -Wall -std=c11 -Wl,-Map=output.map")

# Linker flags
set(CMAKE_EXE_LINKER_FLAGS "-T ../linker/lnk_msp430g2553.cmd")


add_subdirectory(lib/platform)
add_subdirectory(lib/gpio)
add_subdirectory(lib/dio)
add_subdirectory(lib/icu)
add_subdirectory(lib/bcm)
add_subdirectory(lib/wdt)

# add_executable(Libraries src/library.c)
add_executable(APPL${PROJECT_VERSION}.out ${SOURCES} ${SRC_DIR}/library.c)
target_link_libraries(APPL${PROJECT_VERSION}.out gpio_lib platform_lib dio_lib icu_lib bcm_lib wdt_lib)
