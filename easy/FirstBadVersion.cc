#include "../config.h"

bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int first = 0;
    int test = 0;
    int step = 0;
    int count = n;

    while (count > 0) {
      test = first;
      step = count >> 1;
      test += step;
      if (isBadVersion(test)) {
        count = step;
      } else {
        first = ++test;
        count -= step + 1;
      }
    }

    return first;
  }
};
