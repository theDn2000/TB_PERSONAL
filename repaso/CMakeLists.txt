cmake_minimum_required(VERSION 3.12)
project(Ejemplo)

set(CMAKE_CXX_STANDARD 20)

# Add your source files here
set(SOURCES
    main.cpp
    student.cpp
    node.cpp
)

# Create the executable
add_executable(MyProject ${SOURCES})