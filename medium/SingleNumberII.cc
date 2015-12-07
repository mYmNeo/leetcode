#include "../config.h"

class Solution {
public:
  int singleNumber(int A[], int n) {
    int once = 0, twice = 0, reset = 0;

    for (int i = 0; i < n; i++) {
      twice |= once & A[i];
      once ^= A[i];
      reset = once & twice;
      once ^= reset;
      twice ^= reset;
    }

    return once;
  }
};
