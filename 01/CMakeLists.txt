cmake_minimum_required(VERSION 3.26)
project(01)

set(CMAKE_CXX_STANDARD 14)

add_executable(01A task_A.cpp)
add_executable(01B task_B.cpp)

configure_file(temperatures.txt temperatures.txt COPYONLY)
