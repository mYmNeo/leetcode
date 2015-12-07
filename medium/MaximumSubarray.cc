#include "../config.h"

class Solution {
public:
  int maxSubArray(int A[], int n) {
    std::vector<int> dp(n);
    dp[0] = A[0];

    int result = A[0];
    for (int i = 1; i < n; ++i) {
      dp[i] = std::max(A[i], dp[i - 1] + A[i]);
      result = std::max(result, dp[i]);
    }

    return result;
  }
};
