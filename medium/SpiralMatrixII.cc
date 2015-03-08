#include "../config.h"

class Solution
{
public:
    std::vector<std::vector<int> > generateMatrix(int n)
    {
        std::vector<std::vector<int> > result(n, std::vector<int>(n));
        int row = 0, col = 0;
        int num = 0;
        int loop = 0;

        while (loop < n) {
            row = loop;
            col = loop;

            for ( ; col < n; ++col) {
                result[row][col] = ++num;
            }

            if (row + 1 >= n) {
                break;
            }

            for (++row, --col ; row < n; ++row) {
                result[row][col] = ++num;
            }

            if (col - 1 < loop) {
                break;
            }

            for (--col, --row ; col >= loop; --col) {
                result[row][col] = ++num;
            }

            if (row - 1 < loop) {
                break;
            }

            for (--row, ++col ; row > loop; --row) {
                result[row][col] = ++num;
            }

            ++loop;
            --n;
        }

        return result;
    }
};

