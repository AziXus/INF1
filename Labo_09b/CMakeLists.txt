cmake_minimum_required(VERSION 3.12)
project(Labo_09b)

set(CMAKE_CXX_STANDARD 14)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wconversion -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories(.)

add_executable(Labo_09b annexe.cpp format.cpp main.cpp traitementDate.cpp)
