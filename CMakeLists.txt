cmake_minimum_required(VERSION 3.23)
project(EJ_vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(EJ_vector
        main.cpp
        Vector.cpp
        Vector.h)
