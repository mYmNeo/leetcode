#include "../config.h"

class Solution {
 public:
  std::string intToRoman(int num) {
    std::map<int, std::string, std::greater<int> > lookup{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};

    std::string result;
    while (num) {
      for (auto &it : lookup) {
        if (num >= it.first) {
          result.append(it.second);
          num -= it.first;
          break;
        }
      }
    }

    return result;
  }
};
