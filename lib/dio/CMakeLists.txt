cmake_minimum_required(VERSION 3.22)
project(dio_lib)

# Agrega los archivos fuente de tu librería en la variable "sources"
set(sources
    Dio.c
    # Agrega aquí todos los archivos fuente de tu librería
)

# Agrega los archivos de encabezado en la variable "headers"
set(headers
    Dio.h
    Dio_Types.h
    # Agrega aquí todos los archivos de encabezado de tu librería
)

# Crea la biblioteca estática a partir de los archivos fuente
add_library(dio_lib STATIC ${sources})

# Agrega la carpeta "include" como una ubicación de búsqueda de archivos de encabezado
target_include_directories(dio_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
