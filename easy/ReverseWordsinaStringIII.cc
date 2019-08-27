#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
 public:
  string reverseWords(string s) {
    int begin = 0, end = 0;

    for (; begin < s.size(); begin = end) {
      while (end < s.size() && s[end] != ' ') {
        ++end;
      }

      if (end == s.size()) {
        break;
      }

      swap_range(s, begin, end - 1);
      ++end;
    }

    swap_range(s, begin, end - 1);

    return s;
  }

 private:
  void swap_range(string& str, int s, int e) {
    while (s < e) {
      swap(str[s], str[e]);
      ++s;
      --e;
    }
  }
};