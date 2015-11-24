#include "../config.h"

class Solution {
 public:
  void gameOfLife(std::vector<std::vector<int>>& board) {
    if (board.empty()) {
      return;
    }

    const int row = board.size();
    const int col = board.front().size();

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        check(board, i, j, i + 1, j - 1);
        check(board, i, j, i + 1, j);
        check(board, i, j, i + 1, j + 1);
        check(board, i, j, i, j + 1);
        if (board[i][j] >= 5 && board[i][j] <= 7) {
          board[i][j] = 1;
        } else {
          board[i][j] = 0;
        }
      }
    }
  }

 private:
  void check(std::vector<std::vector<int>>& board, int i, int j, int a, int b) {
    const int row = board.size();
    const int col = board.front().size();

    if (a >= row || b < 0 || b >= col) {
      return;
    }

    if (board[i][j] % 2) {
      board[a][b] += 2;
    }

    if (board[a][b] % 2) {
      board[i][j] += 2;
    }
  }
};
