#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int island = 0, neighbour = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid.front().size(); ++j) {
        if (grid[i][j]) {
          ++island;
          if (i < grid.size() - 1 && grid[i + 1][j]) {
            ++neighbour;
          }
          if (j < grid.front().size() - 1 && grid[i][j + 1]) {
            ++neighbour;
          }
        }
      }
    }

    return (island << 2) - (neighbour << 1);
  }
};