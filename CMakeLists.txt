cmake_minimum_required(VERSION 3.13)
project(Ass1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ass1
        plan
        README.md test.c test.h)
