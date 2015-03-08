#include "../config.h"

class Solution
{
public:
    void sortColors(int A[], int n)
    {
        int red = -1, white = -1, blue = -1;

        for (int i = 0; i < n; ++i) {
            switch(A[i]) {
                case 0:
                    {
                        A[++blue] = 2;
                        A[++white] = 1;
                        A[++red] = 0;
                        break;
                    }
                case 1:
                    {
                        A[++blue] = 2;
                        A[++white] = 1;
                        break;
                    }
                case 2:
                    {
                        A[++blue] = 2;
                        break;
                    }
                default:
                    {
                        break;
                    }
            }
        }
    }
};

