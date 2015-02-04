#include "config.h"

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        std::string new_str = append(s);
        std::vector<int> p_length(new_str.length());

        int center = 0, right = 0;
        int i_mirror = 0;

        for (int i = 1; i < (int) new_str.length(); ++i) {
            i_mirror = (center << 1) - i;

            p_length[i] = right > i ? std::min(right - i, p_length[i_mirror]) : 0;

            while (new_str[i + 1 + p_length[i]] == new_str[i - 1 - p_length[i]]) {
                p_length[i]++;
            }

            if (i + p_length[i] > right) {
                center = i;
                right = i + p_length[i];
            }
        }

        int max_length = 0;
        center = 0;
        for (int i = 0; i < (int) p_length.size(); ++i) {
            if (max_length < p_length[i]) {
                center = i;
                max_length = p_length[i];
            }
        }

        return s.substr((center - 1 - max_length) >> 1, max_length);
    }
private:
    std::string append(std::string s)
    {
        if (s.length() == 0) {
            return "^$";
        }

        std::string ret = "^";
        for (auto a : s) {
            ret.push_back('#');
            ret.push_back(a);
        }

        ret.append("#$");

        return ret;
    }
};
