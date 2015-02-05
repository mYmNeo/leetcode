#include "config.h"

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int profit = 0;

        if (prices.size() == 0) {
            return 0;
        }

        int min = prices[0];
        int max = prices[0];

        for (int i = 0; i < (int) prices.size(); ++i) {
            if (max > prices[i]) {
                profit += max - min;
                min = prices[i];
            } 
            max = prices[i];
        }

        profit += max - min;
        return profit;
    }
};

