#include "piece.cpp"

class King : public Piece {
public:
    explicit King(Color color) : Piece(color) {}

    std::string type() const override {return  color_string() + " king";}

    std::string symbol() const override  {return (color_string()=="white") ? "O" : "D";}

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
        int dx = abs(from_x - to_x);
        int dy = abs(from_y - to_y);
        return (dx <= 1 && dy <= 1) && !(dx == 0 && dy == 0);
    }
};