cmake_minimum_required(VERSION 3.12)
project(ex_3_28)

set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wconversion -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(ex_3_28 main.cpp)