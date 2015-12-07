#include "../config.h"

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    int length = 1;
    int last = 0;

    if (n == 0 || n == 1) {
      return n;
    }

    last = A[0];

    for (int i = 1; i < n; i++) {
      if (A[i] == last) {
        continue;
      }
      A[length++] = A[i];
      last = A[i];
    }

    return length;
  }
};
