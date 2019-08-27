#include "../config.h"

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.length() <= 1) {
      return s.length();
    }

    int start = 0;
    int max = 0;

    std::unordered_map<char, int> uniq;
    for (int i = 0; i < (int)s.length(); ++i) {
      if (uniq.find(s[i]) != uniq.end()) {
        start = std::max(start, uniq[s[i]] + 1);
      }
      max = std::max(max, i - start + 1);
      uniq[s[i]] = i;
    }

    return max;
  }
};
