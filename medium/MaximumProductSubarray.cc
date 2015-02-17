#include "../config.h"

class Solution
{
public:
    int maxProduct(int A[], int n)
    {
        int result = A[0];
        int max = A[0], min = A[0];

        for (int i = 1; i < n; ++i) {
            if (A[i] > 0) {
                max = std::max(max * A[i], A[i]);
                min = std::min(min * A[i], A[i]);
            } else {
                int temp = max;
                max = std::max(min * A[i], A[i]);
                min = std::min(temp * A[i], A[i]);
            }
            result = std::max(max, result);
        }

        return result;
    }
};

