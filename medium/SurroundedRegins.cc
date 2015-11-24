#include "../config.h"

class Solution {
 public:
  void solve(std::vector<std::vector<char> > &board) {
    int rows = board.size();
    if (rows == 0) {
      return;
    }

    int cols = board[0].size();
    if (cols == 0) {
      return;
    }

    std::pair<int, int> end = std::make_pair(rows, cols);
    for (int j = 0; j < cols; j++) {
      if (board[0][j] == 'O') {
        bfs_replace(board, std::make_pair(0, j), end);
      }
    }

    for (int j = 0; j < cols; j++) {
      if (board[rows - 1][j] == 'O') {
        bfs_replace(board, std::make_pair(rows - 1, j), end);
      }
    }

    for (int i = 0; i < rows; ++i) {
      if (board[i][0] == 'O') {
        bfs_replace(board, std::make_pair(i, 0), end);
      }
    }

    for (int i = 0; i < rows; ++i) {
      if (board[i][cols - 1] == 'O') {
        bfs_replace(board, std::make_pair(i, cols - 1), end);
      }
    }

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == '1') {
          board[i][j] = 'O';
        }
      }
    }
  }

 private:
  void bfs_replace(std::vector<std::vector<char> > &board,
                   std::pair<int, int> cur, std::pair<int, int> &end) {
    std::queue<std::pair<int, int> > next;
    int d_x[4] = {-1, 0, 1, 0};
    int d_y[4] = {0, 1, 0, -1};

    next.push(cur);

    while (!next.empty()) {
      std::pair<int, int> cur = next.front();
      next.pop();

      if (cur.first < 0 || cur.first == end.first || cur.second < 0 ||
          cur.second == end.second) {
        continue;
      }

      if (board[cur.first][cur.second] == 'O') {
        board[cur.first][cur.second] = '1';

        for (int i = 0; i < 4; i++) {
          next.push(std::make_pair(cur.first + d_x[i], cur.second + d_y[i]));
        }
      }
    }
  }
};
