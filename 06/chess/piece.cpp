#pragma once

#include "color.cpp"
#include <string>

class Piece {
public:
    explicit Piece(Color color) : color(color) {}
    virtual ~Piece() = default;
    Color color;
    std::string color_string() const {return (color == Color::WHITE) ? "white" : "black";}
    /// Return color and type of the chess piece
    virtual std::string type() const = 0;
    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    /// Returns the symbol of the piece
    virtual std::string symbol() const = 0;
};

