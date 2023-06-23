cmake_minimum_required(VERSION 3.22)

project(dio_lib)

set(CMAKE_C_COMPILER $ENV{HOME}/Tools/msp430-gcc/msp430-gcc-9.3.1.11_linux64/bin/msp430-elf-gcc)

set(CMAKE_C_FLAGS "-c -mmcu=msp430g2553")

include_directories(../platform)

# Set include directories and sources
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCES
    dio.c
)

# Create static library
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Configure library compilation options
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})

# Configure additional compilation options, if needed
target_compile_options(${PROJECT_NAME} PRIVATE -mmcu=msp430g2553)

# Configure linking options, if needed
# target_link_libraries(${PROJECT_NAME} ...)

# Configure installation options, if needed
# install(TARGETS ${PROJECT_NAME} DESTINATION lib)
# install(FILES ... DESTINATION include)
