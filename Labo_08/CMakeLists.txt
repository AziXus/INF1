cmake_minimum_required(VERSION 3.12)
project(Labo_08)

set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wconversion -Wextra -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories(${MY_SOURCE_DIR})

add_executable(Labo_08 main.cpp reflex.cpp annexe.cpp chrono.cpp)