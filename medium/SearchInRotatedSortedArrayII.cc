#include "../config.h"

class Solution {
public:
  bool search(int A[], int n, int target) {
    int l = 0, r = n - 1;

    while (l <= r) {
      int m = (l + r) >> 1;

      if (A[m] == target) {
        return true;
      }

      if (A[m] > A[l]) {
        if (A[l] <= target && target <= A[m]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      } else if (A[l] > A[m]) {
        if (A[m] <= target && target <= A[r]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      } else {
        ++l;
      }
    }

    return false;
  }
};
