#include "../config.h"

class Solution {
 public:
  void reverseWords(std::string &s) {
    if (s.length() == 0) {
      return;
    }

    int rs = 0, re = s.length() - 1;

    while (rs < re) {
      std::swap(s[rs++], s[re--]);
    }

    int start = 0, end = s.length();
    int write = 0;
    while (start < end) {
      while (s[start] && s[start] == ' ') {
        ++start;
      }

      if (start >= end) {
        break;
      }

      int ns = start;
      while (s[ns] && s[ns] != ' ') {
        ++ns;
      }

      if (ns >= end) {
        break;
      }

      int i = start, j = ns - 1;
      while (i < j) {
        std::swap(s[i], s[j]);
        ++i;
        --j;
      }

      int length = ns - start;
      while (length--) {
        s[write++] = s[start++];
      }
      s[write++] = ' ';
    }

    if (start < end) {
      int i = start, j = end - 1;
      while (i < j) {
        std::swap(s[i], s[j]);
        ++i;
        --j;
      }
      int length = end - start;
      while (length--) {
        s[write++] = s[start++];
      }
      s[write++] = ' ';
    }

    s.resize(write ? write - 1 : 0);
  }
};
