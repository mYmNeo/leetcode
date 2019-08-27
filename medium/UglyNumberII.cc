#include "../config.h"

/**
 * The naive approach is to call isUgly for every number until you reach the nth
 * one. Most numbers are not ugly. Try to focus your effort on generating only
 * the ugly ones.
 * An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly
 * number.
 * The key is how to maintain the order of the ugly numbers. Try a similar
 * approach of merging from three sorted lists: L1, L2, and L3.
 * Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 *
 * 3, L3 * 5).
 */
class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> dp(1, 1);
    int two = 0, three = 0, five = 0;
    while ((int)dp.size() < n) {
      dp.push_back(min(dp[two] * 2, min(dp[three] * 3, dp[five] * 5)));
      if (dp.back() == dp[two] * 2) {
        ++two;
      }
      if (dp.back() == dp[three] * 3) {
        ++three;
      }
      if (dp.back() == dp[five] * 5) {
        ++five;
      }
    }

    return dp.back();
  }
};
