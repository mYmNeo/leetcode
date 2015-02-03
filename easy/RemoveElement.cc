#include "config.h"

class Solution
{
public:
    int removeElement(int A[], int n, int element)
    {
        if (n == 0) {
            return 0;
        }

        int length = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == element) {
                continue;
            }

            A[length++] = A[i];
        }

        return length;
    }
};

