#include "../config.h"

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int> > &matrix, int target)
    {
        if (matrix.size() == 0) {
            return false;
        }

        std::vector<int> index;
        for (auto &it : matrix) {
            index.push_back(it.front());
        }

        int i = lower_bound(index, target);

        if (i == (int) index.size() || matrix[i].front() > target) {
            if (i == 0) {
                return false;
            } else {
                int j = lower_bound(matrix[i - 1], target);
                return (!(j == (int) matrix[i - 1].size())) && matrix[i - 1][j] == target;
            }
        } 

        return true;
    }
private:
    int lower_bound(std::vector<int> &index, int target)
    {
        int start = 0, count = index.size();

        while (count) {
            int step = (count >> 1);

            if (index[start + step] < target) {
                start += step + 1;
                count -= step + 1;
            } else {
                count = step;
            }
        }

        return start;
    }
};

