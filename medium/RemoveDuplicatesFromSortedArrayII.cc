#include "../config.h"

class Solution {
 public:
  int removeDuplicates(int A[], int n) {
    int length = 0;

    int cur = 0, next = 0;

    while (cur < n) {
      next = cur;

      while (next < n && A[cur] == A[next]) {
        ++next;
      }

      int i = 0;
      while (i < 2 && cur + i < next) {
        A[length++] = A[cur];
        ++i;
      }

      cur = next;
    }

    return length;
  }
};
