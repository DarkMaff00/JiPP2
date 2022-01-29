cmake_minimum_required(VERSION 3.16)
project(MainProject)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(MainProject src/main.cpp
        src/user.cpp
        src/account.cpp
        src/savings.cpp
        src/currency.cpp
        src/normal.cpp
        src/menu.cpp)