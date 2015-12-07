#include "../config.h"

class Solution {
public:
  std::vector<std::string> restoreIpAddresses(std::string s) {
    std::vector<std::string> ret;
    std::vector<std::string> test, next;
    int i = 1;

    int num = 0;
    int j = 1;
    int start = 0;

    while (j <= 3) {
      num = num * 10 + s[j] - '0';
      if (num == 0) {
        test.push_back("0.");
        break;
      } else if (num < 256) {
        test.push_back(s.substr(0, j).append("."));
      }
      ++j;
    }

    while (i < 4) {
      next.clear();
      for (std::string &item : test) {
        start = item.length() - i;

        num = 0;
        j = 1;
        while (j <= 3 && start + j - 1 < (int)s.length()) {
          num = num * 10 + s[start + j - 1] - '0';
          if (num == 0) {
            next.push_back(std::string(item).append("0."));
            break;
          } else if (num < 256) {
            next.push_back(
                std::string(item).append(s.substr(start, j)).append("."));
          }
          ++j;
        }
      }
      test.swap(next);
      ++i;
    }

    for (std::string &item : test) {
      if (item.length() - 4 == s.length()) {
        item.pop_back();
        ret.push_back(item);
      }
    }

    return ret;
  }
};
