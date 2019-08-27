#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    }

    int prev = 10, next = 0;
    int factor = 9, sum = 1;
    for (int i = 1; i < n && factor > 0; ++i) {
      sum *= factor--;
      next = prev + sum * 9;
      prev = next;
    }
    return prev;
  }
};
