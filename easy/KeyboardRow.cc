#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
 public:
  Solution() {
    lookup.resize(26);
    vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
    int index;

    for (int i = 0; i < rows.size(); ++i) {
      index = 1 << i;
      for (auto c : rows[i]) {
        lookup[c - 'A'] = index;
      }
    }
  }

 public:
  vector<string> findWords(vector<string>& words) {
    vector<string> ret;
    int id;

    for (auto str : words) {
      id = 7;
      for (auto c : str) {
        id &= lookup[toupper(c) - 'A'];
        if (id == 0) {
          break;
        }
      }

      if (id) {
        ret.push_back(str);
      }
    }

    return ret;
  }

 private:
  vector<int> lookup;
};