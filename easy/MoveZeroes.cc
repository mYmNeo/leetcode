#include "../config.h"

class Solution {
 public:
  void moveZeroes(std::vector<int>& nums) {
    int length = nums.size();
    for (int r = 0, c = 0; r < length; ++r, ++c) {
      while (r < length && !nums[r]) {
        ++r;
      }
      if (r == length) break;
      if (!nums[c]) {
        nums[c] = nums[r];
        nums[r] = 0;
      }
    }
  }
};
