#include "../config.h"

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
      prev_buy = buy;
      buy = std::max(prev_sell - price, buy);
      prev_sell = sell;
      sell = std::max(prev_buy + price, sell);
    }
    return sell;
  }
};
