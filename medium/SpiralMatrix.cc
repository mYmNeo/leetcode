#include "../config.h"

class Solution {
 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int> > &matrix) {
    std::vector<int> result;
    int m = matrix.size();

    if (m == 0) {
      return result;
    }

    int n = matrix.front().size();
    int loop = 0;
    int row = 0, col = 0;

    while (loop < m && loop < n) {
      row = col = loop;

      for (; col < n; ++col) {
        result.push_back(matrix[row][col]);
      }

      if (row + 1 >= m) {
        break;
      }

      for (++row, --col; row < m; ++row) {
        result.push_back(matrix[row][col]);
      }

      if (col - 1 < loop) {
        break;
      }

      for (--col, --row; col >= loop; --col) {
        result.push_back(matrix[row][col]);
      }

      if (row - 1 < loop) {
        break;
      }

      for (--row, ++col; row > loop; --row) {
        result.push_back(matrix[row][col]);
      }

      ++loop;
      --n;
      --m;
    }

    return result;
  }
};
