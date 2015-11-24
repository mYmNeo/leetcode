#include "../config.h"

class Solution {
 public:
  int rob(std::vector<int>& nums) {
    int size = nums.size();

    if (size == 0) {
      return 0;
    }

    if (size == 1) {
      return nums.front();
    }

    std::vector<int> dp(size + 1, 0);

    dp[1] = nums.front();

    for (int i = 2; i < size; ++i) {
      dp[i] = std::max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }

    return dp.back();
  }
};
