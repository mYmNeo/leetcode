#include "../config.h"

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &num) {
    std::vector<std::vector<int>> result;

    if (num.size() == 0) {
      return result;
    }

    std::sort(num.begin(), num.end());

    for (int i = 0; i < (int)num.size(); ++i) {
      int remaining = -num[i];

      int start = i + 1;
      int end = num.size() - 1;

      while (start < end) {
        int sum = num[start] + num[end];

        if (sum == remaining) {
          std::vector<int> item{num[i], num[start], num[end]};
          result.push_back(item);
          while (num[start] == item[1] && start < end) {
            start++;
          }

          while (item[2] == num[end] && start < end) {
            end--;
          }
          continue;
        }

        if (sum < remaining) {
          start++;
          continue;
        }

        end--;
      }

      while (i + 1 < (int)num.size() && num[i + 1] == num[i]) {
        i++;
      }
    }

    return result;
  }
};
