#include "../config.h"

class Solution {
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int size =
        std::abs(D - B) * std::abs(A - C) + std::abs(G - E) * std::abs(H - F);

    int left = std::max(std::min(A, C), std::min(E, G));
    int right = std::min(std::max(A, C), std::max(E, G));
    int bottom = std::max(std::min(B, D), std::min(F, H));
    int top = std::min(std::max(B, D), std::max(F, H));

    if (left > right || bottom > top) {
      return size;
    }

    return size - (right - left) * (top - bottom);
  }
};
