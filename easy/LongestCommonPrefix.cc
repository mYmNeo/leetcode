#include "../config.h"

class Solution {
 public:
  std::string longestCommonPrefix(std::vector<std::string> &str) {
    if (str.size() == 0) {
      return "";
    }

    int length = str[0].length();
    int same_len = length;

    for (int i = 1; i < (int)str.size() && length; ++i) {
      length = std::min(length, (int)str[i].length());

      int same = 0;
      while (same < length && str[0][same] == str[i][same]) {
        same++;
      }

      same_len = std::min(same, same_len);
    }

    return str[0].substr(0, same_len);
  }
};
