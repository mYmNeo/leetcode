#include "../config.h"

class Solution {
 public:
  int longestValidParentheses(std::string s) {
    std::vector<int> dp(s.length() + 1, 0);

    int left = 0;
    for (int i = 1; i <= (int)s.length(); ++i) {
      if (s[i - 1] == '(') {
        ++left;
      } else {
        if (left) {
          --left;
          dp[i] = 2;
          if (s[i - 2] == ')') {
            dp[i] += dp[i - 1];
          }
          dp[i] += dp[i - dp[i]];
        }
      }
    }

    return *std::max_element(dp.begin(), dp.end());
  }
};
