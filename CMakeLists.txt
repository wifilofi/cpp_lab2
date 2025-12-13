cmake_minimum_required(VERSION 3.22)
project(cpp_lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)
include_directories(include)

add_executable(cpp_lab2
        src/Main.cpp
        include/Array.h)

add_executable(ArrayTest
        tests/ArrayTest.cpp
        tests/ArrayTest.cpp
)


target_link_libraries(
        ArrayTest
        gtest
)