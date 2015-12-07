#include "../config.h"

#define PROTOTYPE 1

class Solution {
public:
#if PROTOTYPE
  void solveSudoku(std::vector<std::vector<char>> &board)
#else
  void solveSudoku(std::vector<std::string> &board)
#endif
  {
    solve_helper(board, 0);
  }

private:
#if PROTOTYPE
  bool solve_helper(std::vector<std::vector<char>> &board, int left)
#else
  bool solve_helper(std::vector<std::string> &board, int pos)
#endif
  {
    if (pos == 81) {
      return true;
    }

    int i = pos / 9;
    int j = pos % 9;

    if (board[i][j] != '.') {
      return solve_helper(board, pos + 1);
    } else {
      for (char k = '1'; k <= '9'; ++k) {
        if (is_row_valid(board, i, k) && is_col_valid(board, j, k) &&
            is_rect_valid(board, i, j, k)) {
          board[i][j] = k;
          if (solve_helper(board, pos + 1)) {
            return true;
          } else {
            board[i][j] = '.';
          }
        }
      }
    }

    return false;
  }

#if PROTOTYPE
  bool is_row_valid(std::vector<std::vector<char>> &board, int row, char c)
#else
  bool is_row_valid(std::vector<std::string> &board, int row, char c)
#endif
  {
    for (int j = 0; j < 9; ++j) {
      if (board[row][j] == c) {
        return false;
      }
    }

    return true;
  }

#if PROTOTYPE
  bool is_col_valid(std::vector<std::vector<char>> &board, int col, char c)
#else
  bool is_col_valid(std::vector<std::string> &board, int col, char c)
#endif
  {
    for (int i = 0; i < 9; ++i) {
      if (board[i][col] == c) {
        return false;
      }
    }

    return true;
  }

#if PROTOTYPE
  bool is_rect_valid(std::vector<std::vector<char>> &board, int row, int col,
                     char c)
#else
  bool is_rect_valid(std::vector<std::string> &board, int row, int col, char c)
#endif
  {
    row = (row / 3) * 3;
    col = (col / 3) * 3;

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (board[row + i][col + j] == c) {
          return false;
        }
      }
    }

    return true;
  }
};
