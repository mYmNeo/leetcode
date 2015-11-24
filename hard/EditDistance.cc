#include "../config.h"

class Solution {
 public:
  int minDistance(std::string word1, std::string word2) {
    std::vector<std::vector<int> > dp(word1.length() + 1,
                                      std::vector<int>(word2.length() + 1, 0));

    for (int j = 0; j < (int)word2.length(); ++j) {
      dp[0][j + 1] = j + 1;
    }

    for (int i = 0; i < (int)word1.length(); ++i) {
      dp[i + 1][0] = i + 1;
    }

    for (int i = 0; i < (int)word1.length(); ++i) {
      for (int j = 0; j < (int)word2.length(); ++j) {
        if (word1[i] == word2[j]) {
          dp[i + 1][j + 1] = dp[i][j];
        } else {
          dp[i + 1][j + 1] =
              std::min(std::min(dp[i + 1][j], dp[i][j + 1]), dp[i][j]) + 1;
        }
      }
    }

    return dp.back().back();
  }
};
