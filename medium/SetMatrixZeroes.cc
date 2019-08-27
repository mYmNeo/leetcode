#include "../config.h"

class Solution {
public:
  void setZeroes(std::vector<std::vector<int>> &matrix) {
    bool col0 = false;
    for (int i = 0; i < (int)matrix.size(); ++i) {
      if (matrix[i][0] == 0) {
        col0 = true;
      }

      for (int j = 1; j < (int)matrix.front().size(); ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = matrix.size() - 1; i >= 0; --i) {
      for (int j = matrix.front().size() - 1; j > 0; --j) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }

      if (col0) {
        matrix[i][0] = 0;
      }
    }
  }
};
