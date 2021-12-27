cmake_minimum_required(VERSION 3.17)
project(lab2)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
set(CMAKE_CXX_STANDARD 14)

add_executable(lab2 main.cpp HashTable.cpp HashTable.h test/test.cpp)
target_link_libraries(lab2 gtest gtest_main)

