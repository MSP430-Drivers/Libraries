cmake_minimum_required(VERSION 3.22)

project(bcm_lib)

set(CMAKE_C_COMPILER $ENV{HOME}/Tools/msp430-gcc/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-gcc)

include_directories(../platform/include)
include_directories(../utils/include)

set(SRC_DIR src)

# Set include directories and sources
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
    ${SRC_DIR}/bcm.c
)

# Create static library
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Configure library compilation options
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})

# Configure additional compilation options, if needed
target_compile_options(${PROJECT_NAME} PRIVATE -c -mmcu=msp430g2553 -std=c11 -Wall)

# Configure linking options, if needed
# target_link_options(${PROJECT_NAME} PRIVATE -Wl,-Map=output.map)

# Configure installation options, if needed
# install(TARGETS ${PROJECT_NAME} DESTINATION lib)
# install(FILES ... DESTINATION include)
