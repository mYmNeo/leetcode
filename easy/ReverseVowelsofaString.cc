#include "../config.h"

class Solution {
public:
  string reverseVowels(string s) {
    int i = 0, j = (int)s.length() - 1;

    while (i < j) {
      while (i < (int)s.length() && !isVowels(s[i])) {
        ++i;
      }

      if (i == (int)s.length()) {
        break;
      }

      while (j >= 0 && !isVowels(s[j])) {
        --j;
      }

      if (j < 0) {
        break;
      }

      if (i < j) {
        swap(s[i++], s[j--]);
      }
    }

    return s;
  }

  bool isVowels(char &c) {
    switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      return true;
    default:
      break;
    }
    return false;
  }
};
