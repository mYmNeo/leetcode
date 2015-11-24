#include "../config.h"

class Solution {
 public:
  bool isPalindrome(int x) {
    int64_t num = 0;
    int copy = x;

    while (copy > 0) {
      num *= 10;
      num += copy % 10;
      copy /= 10;
    }

    return num == x;
  }
};
