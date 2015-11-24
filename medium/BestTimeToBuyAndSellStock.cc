#include "config.h"

class Solution {
 public:
  int maxProfit(std::vector<int> &prices) {
    int profit = 0;

    if (prices.size() == 0) {
      return 0;
    }

    int min = prices.front();
    int max = prices.front();

    for (auto i : prices) {
      if (min > i) {
        profit = std::max(profit, max - min);
        min = i;
        max = i;
      }
      max = std::max(max, i);
    }

    return std::max(profit, max - min);
  }
};
