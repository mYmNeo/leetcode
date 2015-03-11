#include "../config.h"

class Solution
{
public:
    void rotate(int nums[], int n, int k)
    {
        if (n == 0) {
            return;
        }

        std::pair<int, int> temp;
        int index = 0;
        int val = 0;
        int count = 0;

        for (int i = 0; i < k; ++i) {
            temp.first = i;
            temp.second = nums[i];

            do {
                index = (temp.first + k) % n;
                val = nums[index];

                nums[index] = temp.second;
                temp.first = index;
                temp.second = val;
                count++;
            } while (temp.first != i);

            if (count == n) {
                break;
            }
        }
    }
};

