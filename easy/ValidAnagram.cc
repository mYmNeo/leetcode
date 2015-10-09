#include "../config.h"

class Solution
{
  public:
    bool isAnagram(std::string s, std::string t)
    {
      int count[256] = {0}
      for (char& ch : s) {
        count[(int) ch]++;
      }

      for (char& ch : t) {
        count[(int) ch]--;
      }

      for (int& c : count) {
        if (c) {
          return false;
        }
      }

      return true;
    }
};

