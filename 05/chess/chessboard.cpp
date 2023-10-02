#include <iostream>
#include <memory>
#include <vector>
#include "piece.cpp"
#include "king.cpp"

using namespace std;

class ChessBoard {
public:
    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;
        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        cout << piece_to->type() << " is being removed from " << to << endl;
                        if (auto king = dynamic_cast<King *>(piece_to.get()))
                            cout << king->color_string() << " lost the game" << endl;
                    } else {
                        // piece in the from-square has the same color as the piece in the to-square
                        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                        return false;
                    }
                }
                piece_to = std::move(piece_from);
                print_board();
                return true;
            } else {
                cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                return false;
            }
        } else {
            cout << "no piece at " << from << endl;
            print_board();
            return false;
        }
    }

    void print_board() {
        string abc[] = {" A", " B", " C", " D", " E", " F", " G", " H"};
        int counter = 0;

        string board = "--------------------------\n";
        for (auto &row : squares) {
            board.append("|");
            for (const auto & p : row) {
                if (p != nullptr) {
                    board.append(" ").
                            append(p->symbol()).
                            append(" ");
                } else {
                    board.append(" - ");
                }
            }
            board.append("|")
            .append(abc[counter++])
            .append("\n");
        }
        board.append("--------------------------\n").
                append("| 1  2  3  4  5  6  7  8 |");
        cout << "Printing board:" << endl
        << board << endl;
    }
};