#include "../config.h"

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> dict;
    for (auto s : strs) {
      string id(s);
      sort(id.begin(), id.end());
      dict[id].push_back(s);
    }

    vector<vector<string>> ret;
    for (auto kv : dict) {
      sort(kv.second.begin(), kv.second.end());
      ret.push_back(kv.second);
    }
    return ret;
  }
};