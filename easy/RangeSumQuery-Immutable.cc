#include "../config.h"

class NumArray {
public:
  NumArray(std::vector<int> &nums) {
    dp.clear();
    dp.push_back(0);
    for (int n : nums) {
      dp.push_back(dp.back() + n);
    }
  }

  int sumRange(int i, int j) { return dp[j + 1] - dp[i]; }

private:
  std::vector<int> dp;
};
