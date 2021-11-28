cmake_minimum_required(VERSION 3.17)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab3 main.cpp Blocks/ReadFile.h Blocks/WriteFile.h Blocks/Replace.h Blocks/Sort.h Blocks/Grep.h Blocks/Dump.h
        Blocks/ReadFile.cpp Blocks/WriteFile.cpp Blocks/Replace.cpp Blocks/Sort.cpp Blocks/Grep.cpp Blocks/Dump.cpp)