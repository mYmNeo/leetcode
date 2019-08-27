#include "../config.h"

class Solution {
public:
  std::vector<int> getRow(int rowIndex) {
    std::vector<int> ret[2];
    int cur = 0, next = 1;

    ret[cur].push_back(1);

    if (rowIndex == 0) {
      return ret[cur];
    }

    while (rowIndex--) {
      ret[next].clear();
      ret[next].push_back(1);

      for (int i = 0; i < (int)ret[cur].size() - 1; i++) {
        ret[next].push_back(ret[cur][i] + ret[cur][i + 1]);
      }

      ret[next].push_back(1);

      std::swap(cur, next);
    }

    return ret[cur];
  }
};
