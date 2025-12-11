cmake_minimum_required(VERSION 3.22)
project(cpp_lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include_directories(${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



add_executable(ArrayTest src/ArrayTest.cpp)
target_link_libraries(
        ArrayTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ArrayTest)