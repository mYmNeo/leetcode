#include "../config.h"

class Solution
{
public:
    int lengthOfLastWord(const char *s)
    {
        int length = 0;

        while (*s) {
            if (*s == ' ') {
                while (*s && *s == ' ') {
                    s++;
                }

                if (*s) {
                    length = 0;
                }
            } else {
                length++;
                s++;
            }
        }

        return length;
    }
};

