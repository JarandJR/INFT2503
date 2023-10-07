#include <iostream>
#include "chessboard.cpp"

using namespace std;

class ChessBoardPrint {
public:
    explicit ChessBoardPrint(ChessBoard &board) : board(board) {
        board.on_piece_move = [](const Piece &piece, const string &from, const string &to) {
            cout << piece.type() << " is moving from " << from << " to " << to << endl;
        };
        board.on_piece_removed = [](const Piece &piece, const string &square) {
            cout << piece.type() << " is being removed from " << square << endl;
        };
        board.on_lost_game = [](Color color) {
            if (color == Color::WHITE)
                cout << "Black";
            else
                cout << "White";
            cout << " won the game" << endl;
        };
        board.on_piece_move_invalid = [](const Piece &piece, const string &from, const string &to) {
            cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
        };
        board.on_piece_move_missing = [](const string &square) {
            cout << "no piece at " << square << endl;
        };
        board.after_piece_move = [this]() {
            print_board();
        };
    };
    ChessBoard &board;

    void print_board() {
        string abc[] = {" A", " B", " C", " D", " E", " F", " G", " H"};
        int counter = 0;

        string print_board = "--------------------------\n";
        for (auto &row : board.squares) {
            print_board.append("|");
            for (const auto & p : row) {
                if (p != nullptr) {
                    print_board.append(" ").
                            append(p->symbol()).
                            append(" ");
                } else {
                    print_board.append(" - ");
                }
            }
            print_board.append("|")
                    .append(abc[counter++])
                    .append("\n");
        }
        print_board.append("--------------------------\n").
                append("| 1  2  3  4  5  6  7  8 |");
        cout << "Printing board:" << endl
             << print_board << endl << endl;
    }
};