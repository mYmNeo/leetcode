#include "../config.h"

class Solution {
 public:
  std::string countAndSay(int n) {
    std::string result = "1";
    std::string next;

    while (--n) {
      next.clear();
      char last = result[0];
      int count = 0;

      for (int i = 0; i < (int)result.length();) {
        if (result[i] == last) {
          count++;
          ++i;
        } else {
          next.push_back(count + '0');
          next.push_back(last);
          last = result[i];
          count = 0;
        }
      }

      if (count) {
        next.push_back(count + '0');
        next.push_back(last);
      }

      result.swap(next);
    }

    return result;
  }
};
