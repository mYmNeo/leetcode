#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
public:
  int numberOfPatterns(int m, int n) {
    bool keyboard[3][3];
    ret = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        keyboard[i][j] = false;
      }
    }
    for (int p = m; p <= n; ++p) {
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          keyboard[i][j] = true;
          backtrace(keyboard, p - 1, i, j);
          keyboard[i][j] = false;
        }
      }
    }

    return ret;
  }
  void backtrace(bool keyboard[][3], int left, int x, int y) {
    if (left == 0) {
      ++ret;
      return;
    }

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (keyboard[i][j] || (x == i && abs(y - j) > 1 && !keyboard[x][1]) ||
            (y == j && abs(x - i) > 1 && !keyboard[1][y]) ||
            (x + y == i + j && abs(x - i) > 1 && !keyboard[1][1]) ||
            (x - y == i - j && abs(x - i) > 1 && !keyboard[1][1]) ||
            (x == i && y == j)) {
          continue;
        }
        keyboard[i][j] = true;
        backtrace(keyboard, left - 1, i, j);
        keyboard[i][j] = false;
      }
    }
  }

private:
  int ret;
};
