cmake_minimum_required(VERSION 3.28)
project(feup_da_proj2)

set(CMAKE_CXX_STANDARD 17)

add_executable(feup_da_proj2 main.cpp
        Code/src/Interface.cpp
        Code/include/Interface.h
        Code/src/ToyGraph.cpp
        Code/include/ToyGraph.h
        Code/src/FileHandler.cpp
        Code/include/FileHandler.h
        Code/src/Graph.cpp
        Code/include/Graph.h)
