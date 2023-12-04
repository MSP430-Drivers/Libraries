cmake_minimum_required(VERSION 3.22)

project(gpio_lib)

# set(CMAKE_C_COMPILER $ENV{HOME}/Tools/msp430-gcc/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-gcc)

include_directories(../../lib/platform/include)

set(SRC_DIR ../../lib/gpio/src)
set(SRC_DIR_STUBS ../../test/stubs/src)

# Set include directories and sources
set(INCLUDE_DIRS ../../test/stubs/include
                 ../../lib/gpio/include 
                 include)

set(SOURCES
    ${SRC_DIR}/gpio.c
    ${SRC_DIR_STUBS}/register_utils.c
)

# Create static library
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Configure library compilation options
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS} platform_types.h)

# Use FetchContent to download and configure Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG e2239ee6043f73722e7aa812a459f54a28552929 # Use a specific tag or commit hash
)
FetchContent_MakeAvailable(googletest)

add_executable(gpio_lib_tests
    src/test_gpio.cpp
)

# Link Google Test library
target_link_libraries(gpio_lib_tests
    gtest
    gtest_main
    gpio_lib  # library
)

add_test(NAME gpio_lib_tests COMMAND gpio_lib_tests)