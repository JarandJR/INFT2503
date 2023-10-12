cmake_minimum_required(VERSION 3.22.1)
project(06)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.74.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(task1 task1.cpp
        chess/color.cpp
        chess/piece.cpp
        chess/chessboard.cpp
        chess/king.cpp
        chess/knight.cpp
        chess/chessboard_print.cpp
)

add_executable(task2 task2.cpp
        server/connection.cpp
        server/server.cpp
)

target_link_libraries(task2 ${Boost_LIBRARIES})
