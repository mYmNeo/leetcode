#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
 public:
  vector<string> fizzBuzz(int n) {
    vector<string> ret;

    for (int i = 1; i <= n; ++i) {
      string item;

      if (i % 3 == 0 && i % 5 == 0) {
        item = "FizzBuzz";
      } else if (i % 3 == 0) {
        item = "Fizz";
      } else if (i % 5 == 0) {
        item = "Buzz";
      } else {
        item = to_string(i);
      }

      ret.push_back(item);
    }

    return ret;
  }
};