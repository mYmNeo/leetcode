#include "../config.h"

class Solution {
public:
  bool isPowerOfFour(int num) {
    // first we check if the number is power of two, then we check the 1 whether is located
    // at odd position, because 4 -> 100, 16 -> 10000
    return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) == num;
  }
};

