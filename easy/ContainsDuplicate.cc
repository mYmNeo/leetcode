#include "../config.h"

class Solution {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::set<int> count;

    for (int& num : nums) {
      if (count.find(num) != count.end()) {
        return true;
      }

      count.insert(num);
    }

    return false;
  }
};
