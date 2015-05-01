#include "../config.h"

class Solution
{
public:
    int trap(int A[], int n)
    {
        int water = 0;
        int i = 0, j = n - 1;
        int plank = 0;
        while (i <= j) {
            plank = std::max(plank, std::min(A[i], A[j]));
            water += A[i] >= A[j] ? (plank - A[j--]) : (plank - A[i++]);
        }

        return water;
    }
};

