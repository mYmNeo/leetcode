#include "../config.h"

class Solution
{
public:
    bool canJump(int A[], int n)
    {
        int max_reach = 0;

        for (int i = 0; i <= max_reach && i < n; ++i) {
            max_reach = std::max(i + A[i], max_reach);
        }

        return max_reach >= n;
    }
};

