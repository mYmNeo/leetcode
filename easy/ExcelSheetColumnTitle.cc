#include "config.h"

class Solution
{
public:
    std::string convertToTitle(int n)
    {
        std::string ret;

        while (n > 0) {
            int reminder = --n % 26;
            ret.push_back('A' + reminder);
            n /= 26;
        }
        
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};

