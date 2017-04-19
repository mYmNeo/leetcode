#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int index;
    for (int i = 0; i < nums.size(); ++i) {
      index = abs(nums[i]) - 1;
      if (nums[index] > 0) {
        nums[index] = -nums[index];
      }
    }

    vector<int> ret;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        ret.push_back(i + 1);
      }
    }

    return ret;
  }
};