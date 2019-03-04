cmake_minimum_required(VERSION 3.13)
project(Ass1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ass1
        plan
        README.md main.c typedef.h LInkedLists.c LInkedLists.h Sort.c Sort.h Property.c Property.h menu.c menu.h)
