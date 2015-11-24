#include "../config.h"

class Solution {
 public:
  std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates,
                                                int target) {
    res.clear();
    result.clear();
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> save;

    combination_sum_helper(candidates, save, target);

    for (auto &it : res) {
      result.push_back(std::move(it));
    }
    return result;
  }

 private:
  void combination_sum_helper(std::vector<int> &candidates,
                              std::vector<int> &save, int target) {
    if (0 == target) {
      res.insert(save);
      return;
    }

    if (0 > target) {
      return;
    }

    auto it = std::lower_bound(candidates.begin(), candidates.end(),
                               save.empty() ? 0 : save.back());
    for (; it != candidates.end(); ++it) {
      save.push_back(*it);
      combination_sum_helper(candidates, save, target - save.back());
      save.pop_back();
    }
  }

 private:
  std::vector<std::vector<int> > result;
  std::set<std::vector<int> > res;
};
