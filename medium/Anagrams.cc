#include "../config.h"

class Solution
{
public:
    std::vector<std::string> anagrams(std::vector<std::string> &strs)
    {
        std::map<std::string, std::vector<std::string> > tmp;

        for (auto &str : strs) {
            auto copy = str;
            std::sort(str.begin(), str.end());
            tmp[str].push_back(copy);
        }

        std::vector<std::string> result;

        for (auto &pair : tmp) {
            if (pair.second.size() > 1) {
                std::copy(pair.second.begin(), pair.second.end(), std::back_inserter(result));
            }
        }

        return result;
    }
};

