#include "../config.h"

class Solution {
 public:
  std::vector<std::vector<int> > fourSum(std::vector<int> &num, int target) {
    std::vector<std::vector<int> > result;

    std::sort(num.begin(), num.end());
    for (int i = 0; i < (int)num.size(); ++i) {
      std::vector<std::vector<int> > ret =
          threeSum(num, i + 1, target - num[i]);
      for (std::vector<int> &item : ret) {
        item.insert(item.begin(), num[i]);
        result.push_back(item);
      }

      while (i + 1 < (int)num.size() && num[i + 1] == num[i]) {
        i++;
      }
    }

    return result;
  }

 private:
  std::vector<std::vector<int> > threeSum(std::vector<int> &num, int start,
                                          int target) {
    std::vector<std::vector<int> > result;

    if (num.size() - start <= 0) {
      return result;
    }

    for (int i = start; i < (int)num.size(); ++i) {
      int remaining = target - num[i];
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
