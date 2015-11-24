#include "../config.h"

class Solution {
 public:
  int findPeakElement(const std::vector<int> &num) {
    int size = num.size();
    int start = 0;

    while (size > 1) {
      int mid = start + (size >> 1);

      if (mid == 0 || num[mid] > num[mid - 1]) {
        size = size - (mid - start);
        start = mid;
      } else {
        size >>= 1;
      }
    }

    return start;
  }
};
