cmake_minimum_required(VERSION 3.22)
project(dio_lib)

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
# target_compile_options(${PROJECT_NAME} PUBLIC ...)

# Configure linking options, if needed
# target_link_libraries(${PROJECT_NAME} ...)

# Configure installation options, if needed
# install(TARGETS ${PROJECT_NAME} DESTINATION lib)
# install(FILES ... DESTINATION include)
