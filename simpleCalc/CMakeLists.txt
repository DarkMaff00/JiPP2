cmake_minimum_required(VERSION 3.16)

project(simpleCalc)
set(CMAKE_CXX_STANDARD 17)
add_executable(simpleCalc
        src/main.cpp
        src/calc.cpp
        )
include_directories(include)