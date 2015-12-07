#include "../config.h"

class Solution {
public:
  int lengthOfLIS(std::vector<int> &nums) {
    std::vector<int> dp;

    for (int &n : nums) {
      auto pos = std::lower_bound(dp.begin(), dp.end(), n);
      if (pos == dp.end()) {
        dp.push_back(n);
      } else {
        *pos = n;
      }
    }

    return dp.size();
  }
};
