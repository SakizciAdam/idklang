cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(idklang)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/build/")

set(SOURCES
    src/main.cpp
    src/reader.cpp
)

# Add an executable with the above sources
add_executable(idklang ${SOURCES})

target_include_directories(idklang
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/src/include
        ${PROJECT_SOURCE_DIR}/idklang

)
