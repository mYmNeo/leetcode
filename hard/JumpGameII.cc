#include "../config.h"

class Solution
{
public:
    int jump(int A[], int n)
    {
        if (n <= 1) {
            return 0;
        }

        int jumps = 1;
        int max_reach = A[0];
        int cur_reach = A[0];

        for (int i = 1; i <= max_reach && i < n; ++i) {
            cur_reach = std::max(i + A[i], cur_reach);

            if (i == n - 1) {
                return jumps;
            }

            if (i == max_reach) {
                max_reach = cur_reach;
                ++jumps;
            }
        }

        return 0;
    }
};

