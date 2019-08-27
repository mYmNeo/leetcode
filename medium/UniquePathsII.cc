#include "../config.h"

class Solution {
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
    if (obstacleGrid.size() == 0) {
      return 0;
    }

    if (obstacleGrid[0][0] == 1) {
      return 0;
    }

    std::vector<int> dp(obstacleGrid.front().size(), 0);

    dp[0] = 1;
    for (int i = 0; i < (int)obstacleGrid.size(); ++i) {
      for (int j = 0; j < (int)obstacleGrid.front().size(); ++j) {
        if (obstacleGrid[i][j] == 1) {
          dp[j] = 0;
        } else if (j > 0) {
          dp[j] += dp[j - 1];
        }
      }
    }

    return dp.back();
  }
};
