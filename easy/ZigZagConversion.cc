#include "../config.h"

class Solution {
 public:
  std::string convert(std::string s, int rows) {
    std::vector<std::string> data(rows);
    int row = 0;

    if (rows == 1) {
      return s;
    }

    for (int i = 0; i < (int)s.length();) {
      for (; row < rows && i < (int)s.length(); row++) {
        data[row].push_back(s[i++]);
      }
      row -= 2;

      for (; row >= 0 && i < (int)s.length(); row--) {
        data[row].push_back(s[i++]);
      }
      row += 2;
    }

    std::string ret;

    for (int i = 0; i < rows; i++) {
      ret.append(data[i]);
    }

    return ret;
  }
};
