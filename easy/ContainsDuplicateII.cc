#include "../config.h"

class Solution {
public:
  bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
    std::map<int, int> count;

    for (int i = 0; i < (int)nums.size(); ++i) {
      if (count.find(nums[i]) != count.end()) {
        if (count[nums[i]] + k >= i) {
          return true;
        }
      }

      count[nums[i]] = i;
    }

    return false;
  }
};
