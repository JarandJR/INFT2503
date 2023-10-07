cmake_minimum_required(VERSION 3.26)
project(06)

set(CMAKE_CXX_STANDARD 14)

add_executable(task1 task1.cpp
        chess/color.cpp
        chess/piece.cpp
        chess/chessboard.cpp
        chess/king.cpp
        chess/knight.cpp
        chess/chessboard_print.cpp
)
add_executable(task2 task2.cpp
        server/server.cpp
        server/connection.cpp)
