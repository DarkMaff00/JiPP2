cmake_minimum_required(VERSION 3.16)
project(matrixApp)
set(CMAKE_CXX_STANDARD  17)

include_directories(../matrixLib/include)

add_executable(matrixApp main.cpp)

target_link_libraries(matrixApp matrixLib)