cmake_minimum_required(VERSION 3.27)
project(GeneCW)

set(CMAKE_CXX_STANDARD 17)

add_executable(GeneCW main.cpp
        Gene.cpp
        Gene.h
        GeneTest.cpp
        GeneTest.h)
