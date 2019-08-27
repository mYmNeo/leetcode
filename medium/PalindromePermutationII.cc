#include "../config.h"

class Solution {
public:
  vector<string> generatePalindromes(string s) {
    int dict[256] = {0};
    for (auto c : s) {
      ++dict[(int)c];
    }

    int single = 0;
    char special = '\0';
    for (int i = 0; i < 256; ++i) {
      if (dict[i] & 1) {
        ++single;
        special = i;
      }
      dict[i] >>= 1;
    }

    if (single > 1) {
      return vector<string>();
    }

    vector<string> ret;
    string prefix = "";
    for (int i = 0; i < 256; ++i) {
      while (dict[i]-- > 0) {
        prefix.push_back(i);
      }
    }

    do {
      string item;

      item += prefix;
      if (special != '\0') {
        item.push_back(special);
      }
      for (auto i = prefix.rbegin(); i != prefix.rend(); ++i) {
        item.push_back(*i);
      }

      ret.push_back(item);

      int swap = (int)prefix.size() - 2;
      while (swap >= 0 && prefix[swap] >= prefix[swap + 1]) {
        --swap;
      }

      if (swap < 0) {
        break;
      }

      int greater = (int)prefix.size() - 1;
      while (greater > swap && prefix[greater] <= prefix[swap]) {
        --greater;
      }

      ::swap(prefix[swap], prefix[greater]);
      reverse(prefix.begin() + swap + 1, prefix.end());
    } while (1);

    return ret;
  }
};

