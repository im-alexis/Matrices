cmake_minimum_required(VERSION 3.21)
project(Project2_starter_files)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project2_starter_files
        header.c
        main.cpp
        MatrixMultiply.h
        Project2.cpp)
