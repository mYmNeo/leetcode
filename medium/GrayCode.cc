#include "../config.h"

class Solution {
public:
  std::vector<int> grayCode(int n) {
    std::vector<int> result;
    std::vector<int> next;
    int origin = n;

    if (n == 0) {
      result.push_back(0);
      return result;
    }

    result.push_back(0);
    result.push_back(1);
    n--;

    int shift = 1;
    while (n--) {
      for (int &origin : result) {
        next.push_back(origin);
      }

      for (auto it = result.rbegin(); it != result.rend(); ++it) {
        next.push_back(((*it) | (1 << shift)) & ((1 << origin) - 1));
      }

      result = std::move(next);
      ++shift;
    }

    return result;
  }
};
