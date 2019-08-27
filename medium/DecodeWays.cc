#include "../config.h"

class Solution {
public:
  int numDecodings(std::string s) {
    if (s.length() == 0) {
      return 0;
    }

    std::vector<int> dp(s.length() + 1);
    dp[0] = 1;
    dp[1] = (s[0] >= '1' && s[0] <= '9') ? 1 : 0;

    for (int i = 1; i < (int)s.length(); ++i) {
      auto test = is_valid(s[i - 1], s[i]);
      dp[i + 1] = (test.first ? dp[i] : 0) + (test.second ? dp[i - 1] : 0);
    }

    return dp.back();
  }

private:
  std::pair<bool, bool> is_valid(char prev, char next) {
    std::pair<bool, bool> ret(false, false);

    if (next >= '1' && next <= '9') {
      ret.first = true;
    }

    if (prev && prev != '0') {
      int num = (prev - '0') * 10 + next - '0';

      if (num > 0 && num < 27) {
        ret.second = true;
      }
    }

    return ret;
  }
};
