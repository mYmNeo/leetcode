#include "../config.h"

class Solution
{
public:
    int findMin(std::vector<int> &num)
    {
        if (num.size() == 0) {
            return 0;
        }

        int start = 0, end = num.size() - 1;

        while (start < end) {
            int mid = (start + end) >> 1;

            if (num[mid] < num.back()) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return num[start];
    }
};

