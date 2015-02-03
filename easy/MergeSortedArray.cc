#include "config.h"

class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        int pos_a = n;
        int pos_b = 0;
        int cur = 0;

        ::memmove(A + n, A, m * sizeof(int));
        while (pos_a < m + n && pos_b < n) {
            if (A[pos_a] < B[pos_b]) {
                A[cur++] = A[pos_a++];
            } else {
                A[cur++] = B[pos_b++];
            }
        }

        while (pos_a < m + n) {
            A[cur++] = A[pos_a++];
        }

        while (pos_b < n) {
            A[cur++] = B[pos_b++];
        }
    }
};
