#include "../config.h"

class TicTacToe {
 public:
  /** Initialize your data structure here. */
  TicTacToe(int n)
      : rowCount(n),
        colCount(n),
        diagonalCount(0),
        antiDiagonalCount(0),
        size(n) {}

  /** Player {player} makes a move at ({row}, {col}).
      @param row The row of the board.
      @param col The column of the board.
      @param player The player, can be either 1 or 2.
      @return The current winning condition, can be either:
              0: No one wins.
              1: Player 1 wins.
              2: Player 2 wins. */
  int move(int row, int col, int player) {
    int plus = player == 1 ? 1 : -1;
    rowCount[row] += plus;
    colCount[col] += plus;
    if (row == col) {
      diagonalCount += plus;
    }

    if (row + col == size - 1) {
      antiDiagonalCount += plus;
    }

    if (abs(rowCount[row]) == size || abs(colCount[col]) == size ||
        abs(diagonalCount) == size || abs(antiDiagonalCount) == size) {
      return player;
    }
    return 0;
  }
  vector<int> rowCount, colCount;
  int diagonalCount, antiDiagonalCount;
  int size;
};