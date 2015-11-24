#include "../config.h"

class Solution {
 public:
  bool isMatch(const char *s, const char *p) {
    const char *eat = nullptr;
    const char *next = nullptr;

    while (*s) {
      if (*p == '?' || *p == *s) {
        ++s;
        ++p;
      } else if (*p == '*') {
        next = p++;
        eat = s;
      } else if (eat) {
        s = ++eat;
        p = next + 1;
      } else {
        return false;
      }
    }

    while (*p == '*') {
      ++p;
    }

    return *p == '\0';
  }
};
