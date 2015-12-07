#include "../config.h"

class Solution {
public:
  double pow(double x, int n) {
    double result = 1.0;
    uint32_t count = n;

    if (n == INT_MIN) {
      x = 1.0 / x;
      count = INT_MAX;
      ++count;
    } else if (n < 0) {
      x = 1.0 / x;
      count = -n;
    }

    while (count) {
      if (count & 1) {
        result *= x;
      }

      x *= x;
      count >>= 1;
    }

    return result;
  }
};
