#include "../config.h"

class Solution {
public:
  int majorityElement(std::vector<int> &num) {
    int last, count;

    last = 0;
    count = 0;
    for (int i = 0; i < (int)num.size(); ++i) {
      if (count == 0) {
        last = num[i];
        count++;
      } else if (last == num[i]) {
        count++;
      } else if (last != num[i]) {
        count--;
      }
    }

    return last;
  }
};
