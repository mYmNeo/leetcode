#include "../config.h"

class Solution {
public:
  string reverseString(string s) {
    int i = 0, j = (int)s.length() - 1;
    while (i < j) {
      swap(s[i++], s[j--]);
    }

    return s;
  }
};
