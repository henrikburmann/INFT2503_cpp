#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const {
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
    }

    /// Return color and type of the chess piece
    virtual std::string type() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

    virtual std::string position_text() const = 0;
  };

  class King : public Piece {
    std::string type() const override {
      return color_string() + " king";
    };

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      if (from_x - to_x == 0 && from_y - to_y == 0) {
        return false;
      }
      if (abs(from_x - to_x) > 1 || abs(from_y - to_y) > 0) {
        return false;
      }
      return true;
    }
    std::string position_text() const override {
      if (color_string() == "white") {
        return "W-Ki";
      } else {
        return "B-Ki";
      }
    }

  public:
    King(Color color) : Piece(color) {}
  };

  class Knight : public Piece {
    std::string type() const override {
      return color_string() + " knight";
    }

    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      if ((abs(from_x - to_x) == 1 && abs(from_y - to_y) == 2) || (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 1)) {
        return true;
      }
      return false;
    }
    std::string position_text() const override {
      if (color_string() == "white") {
        return "W-Kn";
      } else {
        return "B-Kn";
      }
    }

  public:
    Knight(Color color) : Piece(color) {}
  };

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  function<void(const Piece &piece, const string &from, const string &to)> on_valid_move;
  function<void(const Piece &piece, const string &to)> on_piece_removed;
  function<void(const King &king)> on_game_lost;
  function<void(const Piece &piece, const string &from, const string &to)> on_move_to_friendly_square_invalid;
  function<void(const Piece &piece, const string &from, const string &to)> on_invalid_move;
  function<void(const string &from)> on_no_piece_at_square_invalid;
  function<void(const ChessBoard &board)> on_after_piece_move;

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  // All the differnt move scenarios

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
        // cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
        on_valid_move(*piece_from, from, to);
        auto &piece_to = squares[to_x][to_y];
        if (piece_to) {
          if (piece_from->color != piece_to->color) {
            // cout << piece_to->type() << " is being removed from " << to << endl;
            on_piece_removed(*piece_to, to);
            if (auto king = dynamic_cast<King *>(piece_to.get()))
              on_game_lost(*king);
          } else {
            // piece in the from square has the same color as the piece in the to square
            // cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
            on_move_to_friendly_square_invalid(*piece_from, from, to);
            return false;
          }
        }
        piece_to = move(piece_from);
        on_after_piece_move(*this);
        return true;
      } else {
        // cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
        on_invalid_move(*piece_from, from, to);
        return false;
      }
    } else {
      // cout << "no piece at " << from << endl;
      on_no_piece_at_square_invalid(from);
      return false;
    }
  }
};

class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board_) {
    board_.on_valid_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << piece.type() << " is moving from " << from << " to " << to << endl;
    };
    board_.on_piece_removed = [](const ChessBoard::Piece &piece, const string &to) {
      cout << piece.type() << " is being removed from " << to << endl;
    };
    board_.on_game_lost = [](const ChessBoard::King &king) {
      cout << king.color_string() << " lost the game" << endl;
    };
    board_.on_move_to_friendly_square_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << "can not move " << piece.type() << " from " << from << " to " << to << ". Already a friendly piece there" << endl;
    };
    board_.on_invalid_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
      cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
    };
    board_.on_no_piece_at_square_invalid = [](const string &from) {
      cout << "no piece at " << from << endl;
    };
    board_.on_after_piece_move = [](const ChessBoard &chessboard) {
      string board = "";
      for (int x = 7; x > -1; x--) {
        for (int y = 7; y > -1; y--) {
          auto &piece = chessboard.squares[x][y];
          if (piece) {
            board += " " + piece->position_text() + " ";
          } else {
            board += "   0  ";
          }
        }
        board += "\n";
      }
      cout << board << endl;
    };
  }
};
int main() {
  ChessBoard board;
  ChessBoardPrint print(board);
  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
}
