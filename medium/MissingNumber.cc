#include "../config.h"

class Solution {
 public:
  int missingNumber(std::vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); ++i) {
      int pick = nums[i];
      while (nums[pick] != pick) {
        if (pick >= (int)nums.size()) {
          break;
        }

        std::swap(pick, nums[pick]);
      }
    }

    for (int i = 0; i < (int)nums.size(); ++i) {
      if (i != nums[i]) {
        return i;
      }
    }

    return nums.size();
  }
};
