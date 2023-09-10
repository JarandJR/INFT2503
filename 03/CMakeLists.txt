cmake_minimum_required(VERSION 3.26)
project(03)

set(CMAKE_CXX_STANDARD 14)

add_executable(s_to_upper lecture/string_to_upper.cpp)
add_executable(s_to_n_to_s lecture/number_to_string_and_back.cpp)
add_executable(surface_test lecture/surface_test.cpp)
add_executable(class_in_separate_files lecture/Surface.h
        lecture/Surface.cpp
        lecture/surface_main.cpp)
add_executable(circle circle/test_circle.cpp
        circle/Circle.cpp
        circle/Circle.h)
add_executable(commodity commodity/test_commodity.cpp
        commodity/Commodity.cpp
        commodity/Commodity.h)
add_executable(string_manipulator string_manipulator.cpp)
