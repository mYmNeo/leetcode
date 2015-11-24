#include "../config.h"

class Solution {
 public:
  bool isHappy(int n) {
    std::set<int64_t> record;
    int64_t num = n;

    while (record.insert(num).second) {
      int64_t sum = 0;
      while (num) {
        int64_t remain = num % 10;
        sum += remain * remain;
        num /= 10;
      }

      if (sum == 1) {
        return true;
      }

      num = sum;
    }

    return false;
  }
};
