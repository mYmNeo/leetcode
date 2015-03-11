#include "../config.h"

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        int f, e;
        if (s.length() == 0) {
            return true;
        }

        f = 0;
        e = s.length() - 1;
        while (f < e) {
            if (!std::isalnum(s[f])) {
                f++;
                continue;
            }

            if (!std::isalnum(s[e])) {
                e--;
                continue;
            }

            s[f] = std::tolower(s[f]);
            s[e] = std::tolower(s[e]);

            if (s[f] == s[e]) {
                f++;
                e--;
            } else {
                return false;
            }
        }

        return f == e || (e + 1 == f);
    }
};
