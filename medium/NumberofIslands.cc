#include "../config.h"

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) {
      return 0;
    }

    int row = grid.size();
    int col = grid.front().size();

    int island = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ++island;
        }
      }
    }
    return island;
  }
  void dfs(vector<vector<char>> &grid, int a, int b) {
    int x[] = {-1, 0, 1, 0};
    int y[] = {0, -1, 0, 1};

    int row = grid.size();
    int col = grid.front().size();

    grid[a][b] = '0';
    for (int i = 0; i < 4; ++i) {
      x[i] += a;
      y[i] += b;

      if (x[i] < 0 || x[i] >= row || y[i] < 0 || y[i] >= col) {
        continue;
      } else if (grid[x[i]][y[i]] == '1'){
        dfs(grid, x[i], y[i]);
      }
    }
  }
};

