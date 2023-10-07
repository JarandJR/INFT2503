#pragma once

#include <memory>
#include <vector>
#include <functional>
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

    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
    function<void(const Piece &piece, const string &square)> on_piece_removed;
    function<void(Color color)> on_lost_game;
    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
    function<void(const string &square)> on_piece_move_missing;
    function<void()> after_piece_move;

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
                if (on_piece_move)
                    on_piece_move(*piece_from, from, to);
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        if (on_piece_removed)
                            on_piece_removed(*piece_to, to);
                        if (auto king = dynamic_cast<King *>(piece_to.get())) {
                            if (on_lost_game)
                                on_lost_game(king->color);
                        }
                    } else {
                        if (on_piece_move_invalid)
                            on_piece_move_invalid(*piece_from, from, to);
                        return false;
                    }
                }
                piece_to = std::move(piece_from);
                after_piece_move();
                return true;
            } else {
                if (on_piece_move_invalid)
                    on_piece_move_invalid(*piece_from, from, to);
                return false;
            }
        } else {
            if (on_piece_move_missing)
                on_piece_move_missing(from);
            return false;
        }
    }
};