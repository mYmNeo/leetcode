#include "../config.h"

class Solution {
public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> result, next;

    if (n == 0) {
      return result;
    }

    for (int i = 1; i <= k; ++i) {
      result.push_back(std::vector<int>{i});
    }

    while (--k) {
      next.clear();
      for (auto &it : result) {
        for (int i = it.back() + 1; i <= n; ++i) {
          std::vector<int> copy(it);
          copy.push_back(i);
          next.push_back(copy);
        }
      }
      result.swap(next);
    }

    return result;
  }
};
