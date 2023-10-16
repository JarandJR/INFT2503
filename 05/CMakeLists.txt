cmake_minimum_required(VERSION 3.26)
project(05)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp
        chess/color.cpp
        chess/Piece.cpp
        chess/chessboard.cpp
        chess/king.cpp
        chess/knight.cpp
)
