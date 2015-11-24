#include "../config.h"

class Solution {
 public:
  std::vector<int> plusOne(std::vector<int> &digits) {
    std::vector<int> result;
    int num;
    bool carry = false;
    for (int i = digits.size() - 1; i >= 0; --i) {
      num = digits[i] + (i == (int)digits.size() - 1 ? 1 : 0) + (carry ? 1 : 0);
      result.push_back(num % 10);
      carry = num > 9 ? true : false;
    }

    if (carry) {
      result.push_back(1);
    }

    std::reverse(result.begin(), result.end());

    return result;
  }
};
