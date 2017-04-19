#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_length = 0;
    int i, j;

    for (i = 0; i < nums.size(); ++i) {
      j = i;

      if (!nums[j]) {
        continue;
      }

      while (j < nums.size() && nums[j]) {
        ++j;
      }

      max_length = max(max_length, j - i);
      i = j;
    }

    return max_length;
  }
};