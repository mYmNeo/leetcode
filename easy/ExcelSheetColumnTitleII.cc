#include "config.h"

class Solution
{
public:
    int titleToNumber(std::string s)
    {
        int pos = 0;
        int num = 0;

        while (pos < (int) s.length()) {
            num *= 26;
            num += s[pos] - 'A' + 1;
            pos++;
        }

        return num;
    }
};

