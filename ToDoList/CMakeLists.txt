cmake_minimum_required(VERSION 3.31)
project(ToDoList)

set(CMAKE_CXX_STANDARD 20)

add_executable(ToDoList main.cpp
        file_io.cpp
        file_io.h)
