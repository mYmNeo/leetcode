#include "../config.h"

class Solution
{
public:
    bool wordBreak(std::string s, std::unordered_set<std::string> &dict)
    {
        std::vector<bool> dp(s.length() + 1, false);

        dp[0] = true;

        for (int i = 1; i <= (int) s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = dp[i] || (dp[j] && dict.find(s.substr(j, i - j)) != dict.end());
            }
        }

        return dp.back();
    }
};

