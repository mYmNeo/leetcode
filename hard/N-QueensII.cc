#include "../config.h"

class Solution {
 public:
  int totalNQueens(int n) {
    int ret = 0;

    if (n == 0) {
      return ret;
    }

    std::vector<std::vector<bool> > valid(n, std::vector<bool>(n, false));

    for (int j = 0; j < n; ++j) {
      if (!valid[0][j] && check_valid(valid, 0, j, n)) {
        valid[0][j] = true;
        place_a_queen(ret, valid, 1, n);
        valid[0][j] = false;
      }
    }

    return ret;
  }

 private:
  void place_a_queen(int &num, std::vector<std::vector<bool> > &chess, int put,
                     int row) {
    if (put == row) {
      ++num;
      return;
    }

    for (int j = 0; j < row; ++j) {
      if (!chess[put][j] && check_valid(chess, put, j, row)) {
        chess[put][j] = true;
        place_a_queen(num, chess, put + 1, row);
        chess[put][j] = false;
      }
    }
  }

  bool check_valid(std::vector<std::vector<bool> > &chess, const int &row,
                   const int &col, const int &n) {
    for (int i = 0; i < n; ++i) {
      if (chess[i][col]) {
        return false;
      }
    }

    for (int j = 0; j < n; ++j) {
      if (chess[row][j]) {
        return false;
      }
    }

    for (int i = row, j = col; i < n && j < n; ++i, ++j) {
      if (chess[i][j]) {
        return false;
      }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
      if (chess[i][j]) {
        return false;
      }
    }

    for (int i = row, j = col; i < n && j >= 0; ++i, --j) {
      if (chess[i][j]) {
        return false;
      }
    }

    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
      if (chess[i][j]) {
        return false;
      }
    }

    return true;
  }
};
