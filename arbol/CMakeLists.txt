cmake_minimum_required(VERSION 3.20)
project(arbol)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES main.cpp arbol.cpp)

add_executable(arbol ${SOURCES})