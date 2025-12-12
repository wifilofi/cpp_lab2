cmake_minimum_required(VERSION 3.22)
project(cpp_lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

enable_testing()
include_directories(${CMAKE_SOURCE_DIR}/include)

include(FetchContent)

add_executable(ArrayTest src/ArrayTest.cpp)
target_link_libraries(
        ArrayTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ArrayTest)