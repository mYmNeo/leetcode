#include "../config.h"

class Solution {
 public:
  std::vector<std::vector<int> > permute(std::vector<int> &num) {
    std::vector<std::vector<int> > result;

    if (num.size() == 0) {
      return result;
    }

    std::sort(num.begin(), num.end());

    do {
      result.push_back(num);
      int swap = num.size() - 2, greater = 0;

      while (swap >= 0 && num[swap] >= num[swap + 1]) {
        --swap;
        continue;
      }

      if (swap < 0) {
        break;
      }

      greater = num.size() - 1;

      while (greater > swap && num[greater] <= num[swap]) {
        --greater;
      }

      std::swap(num[greater], num[swap]);
      std::reverse(num.begin() + swap + 1, num.end());
    } while (1);

    return result;
  }
};
