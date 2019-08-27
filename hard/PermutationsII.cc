#include "../config.h"

class Solution {
public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int> &num) {
    std::vector<std::vector<int>> result;
    std::sort(num.begin(), num.end());

    while (1) {
      result.push_back(num);

      int i, j;
      for (i = num.size() - 2; i >= 0; --i) {
        if (num[i] < num[i + 1]) {
          break;
        }
      }

      if (i < 0) {
        break;
      }

      j = num.size() - 1;
      while (j > i && num[j] <= num[i]) {
        --j;
      }

      std::swap(num[i], num[j]);

      ++i;
      j = num.size() - 1;

      while (i < j) {
        std::swap(num[i], num[j]);
        ++i;
        --j;
      }
    }

    return result;
  }
};
