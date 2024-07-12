cmake_minimum_required(VERSION 3.5)

project(tetris LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file (GLOB SOURCES
    ./*.h
    ./*.cpp
)
add_executable(tetris ${SOURCES})

install(TARGETS tetris
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
