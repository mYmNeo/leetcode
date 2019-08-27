#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> ret;
    stack<int> sub;
    unordered_map<int, int> lookup;

    for (auto n : nums) {
      while (!sub.empty() && sub.top() < n) {
        lookup.insert(make_pair(sub.top(), n));
        sub.pop();
      }
      sub.push(n);
    }

    for (auto n : findNums) {
      auto test = lookup.find(n);
      if (test == lookup.end()) {
        ret.push_back(-1);
      } else {
        ret.push_back(test->second);
      }
    }

    return ret;
  }
};