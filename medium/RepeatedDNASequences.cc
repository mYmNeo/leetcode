#include "../config.h"

class Solution {
public:
  std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::vector<std::string> result;

    std::unordered_map<int, int> uniq;
    int id = 0, i = 0;

    while (i < (int)s.length()) {
      if (uniq[id = (id << 3 | (s[i++] & 7)) & 0x3FFFFFFF]++ == 1) {
        result.push_back(s.substr(i - 10, 10));
      }
    }

    return result;
  }
};
