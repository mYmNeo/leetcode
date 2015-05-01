#include "../config.h"

class Solution
{
public:
    void rotate(std::vector<std::vector<int> > &matrix)
    {
        int n = matrix.size();

        if (n == 0 || n == 1) {
            return;
        }
        
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1 - i; ++j) {
                std::swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }

        std::reverse(matrix.begin(), matrix.end());
    }
};

