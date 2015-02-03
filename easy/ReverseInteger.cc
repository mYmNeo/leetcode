#include <iostream>

class Solution
{
public:
    int reverse(int x)
    {
        int64_t num = 0;
        bool negative = x > 0 ? false : true;
    
        if (negative) {
            x = -x;
        }

        while (x > 0) {
            num *= 10;
            num += x % 10;
            x /= 10;
        }

        if (num > INT_MAX) {
            num = 0;
        }

        return negative ? -num : num;
    }
};
