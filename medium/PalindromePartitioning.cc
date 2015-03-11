#include "../config.h"

class Solution
{
public:
    std::vector<std::vector<std::string> > partition(std::string s)
    {
        std::vector<std::vector<std::string> > res, tmp;
        tmp = partition_helper(s);
        for (auto v : tmp) {
            std::reverse(v.begin(), v.end());
            res.push_back(v);
        }

        return res;
    }
private:
    std::vector<std::vector<std::string> > partition_helper(std::string s)
    {
        std::vector<std::vector<std::string> > res, tmp;
        if (s.size() == 0) {
            return tmp;
        }

        for (int i = 1; i <= (int) s.size(); ++i) {
            if (is_palindrome(s.substr(0, i))) {
                tmp = partition_helper(s.substr(i));

                if (tmp.size() == 0) {
                    res.push_back(std::vector<std::string> {s.substr(0, i)});
                    continue;
                }

                for (auto vec : tmp) {
                    vec.push_back(s.substr(0, i));
                    res.push_back(vec);
                }
            }
        }

        return res;
    }
    bool is_palindrome(std::string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
                continue;
            }

            return false;
        }

        return true;
    }
};

