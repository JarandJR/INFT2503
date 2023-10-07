#include "piece.cpp"

class Knight : public Piece {
public:
    explicit Knight(Color color) : Piece(color) {}

    std::string type() const override {return color_string() + " knight";}

    std::string symbol() const override {return (color_string()=="white") ? "r" : "R";}

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
        int dx = abs(from_x - to_x);
        int dy = abs(from_y - to_y);
        return (dx == 1 && dy == 2 || dx == 2 && dy == 1);
    }
};
