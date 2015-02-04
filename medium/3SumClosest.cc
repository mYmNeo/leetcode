#include "../config.h"

class Solution
{
public:
    int threeSumClosest(std::vector<int> &num, int target)
    {
        std::sort(num.begin(), num.end());

        std::pair<int, int> result = std::make_pair(INT_MAX, 0);
        for (int i = 0; i < (int) num.size(); ++i) {
            int left = target - num[i];

            int start = i + 1;
            int end = num.size() - 1;

            while (start < end) {
                int sum = num[start] + num[end];

                if (sum < left) {
                    start++;
                    int diff = ::abs(left - sum);
                    if (diff < result.first) {
                        result.first = diff;
                        result.second = num[i] + sum;
                    }
                    continue;
                }

                if (sum > left) {
                    end--;
                    int diff = ::abs(left - sum);
                    if (diff < result.first) {
                        result.first = diff;
                        result.second = num[i] + sum;
                    }
                    continue;
                }

                return target;
            }
        }

        return result.second;
    }
};

