#include "../config.h"

class Solution
{
  public:
    std::vector<int> singleNumber(std::vector<int>& nums)
    {
      int xor_two = 0;
      for (int& num : nums) {
        xor_two ^= num;
      }

      int set = (xor_two & (xor_two - 1)) ^ xor_two;
      int one[2] = {0, 0};

      for (int& num :nums) {
        if (num & set) {
          one[0] ^= num;
        } else {
          one[1] ^= num;
        }
      }

      std::vector<int> ret;
      ret.push_back(one[0]);
      ret.push_back(one[1]);

      return ret;
    }
};

