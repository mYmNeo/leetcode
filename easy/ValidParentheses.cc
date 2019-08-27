#include "../config.h"

class Solution {
public:
  Solution() {
    _lookup['('] = 1;
    _lookup[')'] = 1;
    _lookup['{'] = 2;
    _lookup['}'] = 2;
    _lookup['['] = 3;
    _lookup[']'] = 3;
  }

  bool isValid(std::string s) {
    if (s.length() == 0) {
      return true;
    }

    std::stack<std::pair<char, int>> frame;
    for (int i = 0; i < (int)s.length(); i++) {
      int cur = _lookup[s[i]];
      if (frame.empty()) {
        frame.push(std::make_pair(s[i], cur));
      } else {
        if (frame.top().second == cur && frame.top().first != s[i]) {
          frame.pop();
        } else {
          frame.push(std::make_pair(s[i], cur));
        }
      }
    }

    return frame.empty();
  }

private:
  std::map<char, int> _lookup;
};
