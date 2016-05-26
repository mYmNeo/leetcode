#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
public:
  int minSubArrayLen(int s, vector<int> &nums) {
    int l = 0, h = 0;
    int sum = 0;
    int ret = INT_MAX;

    while (h < (int)nums.size()) {
      while (h < (int)nums.size() && sum < s) {
        sum += nums[h++];
      }

      if (sum < s) {
        break;
      }

      while (l < h && sum >= s) {
        sum -= nums[l--];
      }

      ret = min(ret, h - l + 1);
    }

    return ret == INT_MAX ? 0 : ret;
  }
};
