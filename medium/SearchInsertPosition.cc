#include "../config.h"

class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    int start = 0, count = n;

    while (count) {
      int step = count >> 1;

      if (A[start + step] < target) {
        start += step + 1;
        count -= step + 1;
      } else {
        count = step;
      }
    }

    return start;
  }
};
