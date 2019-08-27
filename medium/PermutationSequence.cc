#include "../config.h"

class Solution {
public:
  std::string getPermutation(int n, int k) {
    int num[10];
    int permu_count = 1;
    std::string result;

    for (int i = 1; i <= n; ++i) {
      num[i - 1] = i;
      permu_count *= i;
    }

    --k;
    for (int i = 0; i < n; ++i) {
      permu_count = permu_count / (n - i);
      int choose = k / permu_count;
      result.push_back(num[choose] + '0');
      ::memmove(&num[choose], &num[choose + 1],
                sizeof(int) * (n - i - choose - 1));
      k %= permu_count;
    }

    return result;
  }
};
