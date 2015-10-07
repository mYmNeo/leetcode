#include "../config.h"

class Solution
{
  public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t)
    {
      std::set<int64_t> window;

      for (int i = 0; i < (int) nums.size(); ++i) {
        if (i > k) {
          window.erase(nums[i - k - 1]);
        }

        auto pos = window.lower_bound(nums[i] - t);
        if (pos != window.end() && *pos - nums[i] <= t) {
          return true;
        }

        window.insert(nums[i]);
      }

      return false;
    }
};

