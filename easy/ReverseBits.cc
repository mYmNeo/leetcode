#include "../config.h"

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;

        for (int i = 0; i < 32; ++i) {
            result = result | ((n >> i) & 1) << (31 - i);
        }
        return result;
    }
};

