cmake_minimum_required(VERSION 3.30)
project(LibrarySystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(LibrarySystem
        main.cpp
        data/ds/linked_list/List.h
        data/ds/linked_list/List.cpp
)
