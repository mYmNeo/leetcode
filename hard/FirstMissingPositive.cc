#include "../config.h"

class Solution {
 public:
  int firstMissingPositive(int A[], int n) {
    int i;

    for (i = 0; i < n; ++i) {
      if (A[i] > 0 && i + 1 != A[i]) {
        int should = std::min(A[i], n) - 1;
        int next = std::min(A[should], n) - 1;
        if (i != should && next != should) {
          std::swap(A[i], A[should]);
          --i;
        }
      }
    }

    for (i = 0; i < n; ++i) {
      if (i + 1 != A[i]) {
        break;
      }
    }

    return i + 1;
  }
};
