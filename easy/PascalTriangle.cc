#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int> > generate(int numRows)
    {
        std::vector<std::vector<int> > ret;
        std::vector<int> item;

        while (numRows--) {
            item.clear();
            item.push_back(1);

            if (!ret.empty()){
                for (int i = 0; i < (int) ret.back().size() - 1; i++) {
                    item.push_back(ret.back()[i] + ret.back()[i + 1]);
                }
                item.push_back(1);
            }

            ret.push_back(item);
        }

        return ret;
    }
};
