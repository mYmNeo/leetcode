#include "../config.h"

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    std::unordered_map<int, int> lookup;
    std::vector<int> result;

    for (int i = 0; i < (int)numbers.size(); i++) {
      lookup[numbers[i]] = i + 1;
      auto found = lookup.find(target - numbers[i]);
      if (found != lookup.end() && found->second != i + 1) {
        result.push_back(i + 1);
        result.push_back(found->second);
        break;
      }
    }

    return result;
  }
};
