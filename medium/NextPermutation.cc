#include "../config.h"

class Solution {
public:
  void nextPermutation(std::vector<int> &num) {
    int change;

    for (change = (int)num.size() - 2; change >= 0; --change) {
      if (num[change] >= num[change + 1]) {
        continue;
      }

      int next = (int)num.size() - 1;
      while (next > change && num[next] <= num[change]) {
        --next;
      }

      swap(num[next], num[change]);
      reverse(num.begin() + change + 1, num.end());
      return;
    }

    std::sort(num.begin(), num.end());
  }
};
