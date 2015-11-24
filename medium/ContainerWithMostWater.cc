#include "../config.h"

class Solution {
 public:
  int maxArea(std::vector<int> &height) {
    int result = 0;

    for (int i = 0, j = height.size() - 1; i < j;) {
      if (height[i] < height[j]) {
        result = std::max(result, height[i] * (j - i));
        ++i;
      } else {
        result = std::max(result, height[j] * (j - i));
        --j;
      }
    }

    return result;
  }
};
