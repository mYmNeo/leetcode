#include "../config.h"

class Solution
{
  public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums)
    {
      if (!nums.size()) {
        return {};
      }

      std::vector<std::string> ret;

      int front = nums.front();
      int last = nums.front();
      std::string range;
      range.append(std::to_string(last));
      for (int i = 1; i < (int) nums.size(); ++i) {
        if (nums[i] == last + 1) {
          last = nums[i];
        } else {
          if (front != last) {
            range.append("->");
            range.append(std::to_string(last));
          }
          ret.push_back(range);
          range.clear();
          range.append(std::to_string(nums[i]));
          front = nums[i];
          last = nums[i];
        }
      }

      if (range.length()) {
        if (front != last) {
          range.append("->");
          range.append(std::to_string(last));
        }
        ret.push_back(range);
      }

      return ret;
    }
};


