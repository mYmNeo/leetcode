#include "../config.h"

class Solution {
public:
  void nextPermutation(std::vector<int> &num) {
    int change;

    for (change = num.size() - 2; change >= 0; --change) {
      if (num[change] >= num[change + 1]) {
        continue;
      } else {
        for (int i = num.size() - 1; i > change; --i) {
          if (num[i] <= num[change]) {
            continue;
          } else {
            std::swap(num[i], num[change]);
            for (int i = change + 1, j = num.size() - 1; i < j; ++i, --j) {
              std::swap(num[i], num[j]);
            }
            return;
          }
        }
      }
    }

    std::sort(num.begin(), num.end());
  }
};
