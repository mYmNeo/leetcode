#include "../config.h"

class Solution {
 public:
  Solution() {
    _lookup[0] = "";
    _lookup[1] = "";
    _lookup[2] = "abc";
    _lookup[3] = "def";
    _lookup[4] = "ghi";
    _lookup[5] = "jkl";
    _lookup[6] = "mno";
    _lookup[7] = "pqrs";
    _lookup[8] = "tuv";
    _lookup[9] = "wxyz";
  }

  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> result;
    std::deque<std::string> next;

    int size = 1;
    next.push_back("");
    for (char digit : digits) {
      auto append = _lookup[digit - '0'];
      int nsize = 0;
      while (size--) {
        auto cur = next.front();

        for (auto add : append) {
          std::string item = cur;
          item.push_back(add);
          next.push_back(item);
          nsize++;
        }

        next.pop_front();
      }
      size = nsize;
    }

    std::copy(std::begin(next), std::end(next), std::back_inserter(result));

    return result;
  }

 private:
  std::map<int, std::string> _lookup;
};
