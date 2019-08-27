#include "../config.h"

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 0) {
      return INT_MAX;
    }

    uint32_t result = 0;
    bool flag = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
                    ? false
                    : true;

    uint32_t new_dividend, new_divisor;

    new_dividend = dividend < 0 ? -dividend : dividend;
    new_divisor = divisor < 0 ? -divisor : divisor;

    while (new_dividend >= new_divisor) {
      int shift = 0;
      uint32_t num = 0;

      while ((num = new_divisor << shift) < new_dividend) {
        ++shift;
      }

      if (num > new_dividend) {
        --shift;
      }

      result += 1 << shift;
      new_dividend -= (new_divisor << shift);
    }

    return flag ? -result : result == (uint32_t)INT_MIN ? INT_MAX : result;
  }
};
