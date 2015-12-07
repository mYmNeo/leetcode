#include "../config.h"

class Solution {
public:
  int minimumTotal(std::vector<std::vector<int>> &triangle) {
    if (triangle.size() == 0) {
      return 0;
    }

    if (triangle.size() == 1) {
      return triangle[0][0];
    }

    for (int i = 1; i < (int)triangle.size(); ++i) {
      triangle[i][0] += triangle[i - 1].front();
      for (int j = 1; j < (int)triangle[i].size() - 1; ++j) {
        triangle[i][j] += std::min(triangle[i - 1][j - 1], triangle[i - 1][j]);
      }
      triangle[i][triangle[i].size() - 1] += triangle[i - 1].back();
    }

    int min = INT_MAX;
    for (auto num : triangle.back()) {
      min = std::min(min, num);
    }

    return min;
  }
};
