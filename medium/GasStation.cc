#include "config.h"

class Solution
{
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
    {
        int left = 0;
        int start = 0;

        for (int i = 0; i < (int) gas.size(); ++i) {
            left += gas[i];

            if (left < cost[i]) {
                start = i + 1;
                left = 0;
            } else {
                left -= cost[i];
            }
        }

        if (start + 1 == (int) gas.size()) {
            left = 0;
            for (int i = start, count = 0; count < (int) gas.size(); count++, i = (i + 1) % (int) gas.size()) {
                left += gas[i];
                
                if (left < cost[i]) {
                    start++;
                    break;
                } else {
                    left -= cost[i];
                }
            }
        }

        return start == (int) gas.size() ? -1 : start;
    }
};

