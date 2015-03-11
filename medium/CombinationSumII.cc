#include "../config.h"

class Solution
{
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &num, int target)
    {
        result.clear();
        std::sort(num.begin(), num.end());
        std::vector<int> save;

        combination_sum_helper(num, save, num.begin(), target);
        return result;
    }
private:
    void combination_sum_helper(std::vector<int> &num, std::vector<int> &save, std::vector<int>::iterator start, int target)
    {
        if (0 == target) {
            result.push_back(save);
            return;
        }

        if (0 > target) {
            return;
        }

        auto it = std::lower_bound(start, num.end(), save.empty() ? 0 : save.back());
        for ( ; it != num.end(); ++it) {
            if (it != num.begin() && *it == *(it - 1) && it > start) {
                continue;
            }
            save.push_back(*it);
            combination_sum_helper(num, save, it + 1, target - save.back());
            save.pop_back();
        }
    }
private:
    std::vector<std::vector<int> > result;
};
