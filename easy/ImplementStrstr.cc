#include "config.h"

class Solution
{
public:
    int strStr(char *haystack, char *needle)
    {
        int length_a = std::strlen(haystack);
        int length_b = std::strlen(needle);

        if (length_b == 0) {
            return 0;
        }

        if (length_a < length_b) {
            return -1;
        }

        for (int i = 0; i <= length_a - length_b; i++) {
            if (std::strncmp(haystack + i, needle, length_b) == 0) {
                return i;
            }
        }

        return -1;
    }
};

