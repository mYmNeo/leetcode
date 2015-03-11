#include "../config.h"

class Solution
{
public:
    std::vector<std::vector<int> > subsets(std::vector<int> &S)
    {
        std::vector<std::vector<int> > ret;

        std::sort(S.begin(), S.end());

        ret.push_back(std::vector<int>());
        std::for_each(S.begin(), S.end(), [&ret](int &num) {
                ret.push_back(std::vector<int> {num});
        });

        int length = S.size();
        for (int i = 1; i < (int) ret.size(); ++i) {
            int index = upper_bound(S, ret[i].back());
            if (index < length) {
                for (int j = index; j < length; ++j) {
                    std::vector<int> item(ret[i]);

                    item.push_back(S[j]);
                    ret.push_back(item);
                }
            }
        }

        return ret;
    }
private:
    int upper_bound(std::vector<int> &S, int num)
    {
        int start = 0, end = S.size();

        while (start < end) {
            int mid = (start + end) >> 1;

            if (S[mid] <= num) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return start;
    }
};

