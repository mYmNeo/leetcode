#include "../config.h"

class Solution {
public:
  bool isOneEditDistance(string s, string t) {
    int count = 0;
    int i, j;
    if (s.length() == t.length()) {
      for (i = 0; i < (int)s.length(); ++i) {
        if (s[i] == t[i]) {
          continue;
        }
        ++count;
      }

      return count == 1;
    } else if (s.length() + 1 == t.length() || t.length() + 1 == s.length()) {
      for (i = 0, j = 0; i < (int)s.length() && j < (int)t.length();) {
        if (s[i] == t[j]) {
          ++i;
          ++j;
          continue;
        }
        ++count;
        if (s.length() < t.length()) {
          ++j;
        } else {
          ++i;
        }
      }

      if (count == 1) {
        return true;
      }

      return count == 0 && ((i == 0 && j == 0) || i == (int)s.length() ||
                            j == (int)t.length());
    }

    return false;
  }
};
