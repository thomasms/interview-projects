cmake_minimum_required(VERSION 3.10)
project(median)

option(SLOW_WAY "Without changes and optimizations using quickselect instead of quicksort" OFF)

if(SLOW_WAY)
    message(STATUS "Compiling with the slow solution...")
    add_compile_definitions(DO_SLOW_WAY)
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g -O0")
add_executable(ut test-main.cpp tests.cpp median.cpp)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g -O2")
add_executable(app median.cpp app.cpp)
