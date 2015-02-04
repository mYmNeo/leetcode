#include "../config.h"

class Solution
{
public:
    int trailingZeroes(int n)
    {
        if (n < 5) {
            return 0;
        }

        int size = std::log2(n) / std::log2(5);

        int ret = 0;
        /** note: 25 count is 5x5, should count twice */
        for (int i = 1; i <= size; i++) {
            ret += n / std::pow(5, i);
        }

        return ret;
    }
};

