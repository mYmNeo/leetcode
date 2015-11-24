#include "../config.h"

class Solution {
 public:
  std::string getHint(std::string secret, std::string guess) {
    int bull = 0, cow = 0;
    int num[10] = {0};

    for (int i = 0; i < (int)secret.length(); ++i) {
      if (secret[i] == guess[i]) {
        bull++;
      } else {
        int s = secret[i] - '0';
        int g = guess[i] - '0';

        cow += (num[s] > 0) + (num[g] < 0);
        num[s]--;
        num[g]++;
      }
    }

    std::ostringstream output;
    output << bull << "A" << cow << "B";
    return output.str();
  }
};
