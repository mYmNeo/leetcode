#include "../config.h"

class Solution {
 public:
  int minPathSum(std::vector<std::vector<int> > &grid) {
    if (grid.size() == 0) {
      return 0;
    }

    for (int j = 1; j < (int)grid.front().size(); ++j) {
      grid[0][j] += grid[0][j - 1];
    }

    for (int i = 1; i < (int)grid.size(); ++i) {
      grid[i][0] += grid[i - 1][0];
    }

    for (int i = 1; i < (int)grid.size(); ++i) {
      for (int j = 1; j < (int)grid.front().size(); ++j) {
        grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
      }
    }

    return grid.back().back();
  }
};
