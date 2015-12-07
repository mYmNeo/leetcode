#include "../config.h"

class Solution {
public:
  bool wordPattern(std::string pattern, std::string str) {
    std::map<char, std::string> order;
    std::map<std::string, char> inverse;
    std::stringstream io(str);

    std::string word;
    int cur = 0;
    while (std::getline(io, word, ' ')) {
      if (inverse.find(word) != inverse.end()) {
        if (inverse[word] != pattern[cur]) {
          return false;
        }
      } else {
        if (order.find(pattern[cur]) != order.end()) {
          return false;
        }

        order[pattern[cur]] = word;
        inverse[word] = pattern[cur];
      }
      ++cur;
    }

    return cur == (int)pattern.size();
  }
};
