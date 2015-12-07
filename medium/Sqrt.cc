#include "../config.h"

class Solution {
public:
  int sqrt(int x) {
    int start = 0, count = x;
    while (count) {
      int step = count >> 1;

      if ((start + step) < x / (start + step)) {
        start += step + 1;
        count -= step + 1;
      } else {
        count = step;
      }
    }

    return start > x / start ? --start : start;
  }
};
