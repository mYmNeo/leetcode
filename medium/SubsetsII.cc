#include "../config.h"

class Solution {
 public:
  std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &S) {
    std::vector<std::pair<std::vector<int>, int> > ret;

    std::sort(S.begin(), S.end());

    ret.push_back(std::make_pair(std::vector<int>(), -1));
    int last = S[0] - 1;
    int i = 0;
    std::for_each(S.begin(), S.end(), [&](int &num) {
      if (last != num) {
        ret.push_back(std::make_pair(std::vector<int>{num}, i));
      }
      last = num;
      ++i;
    });

    int length = S.size();
    for (int i = 1; i < (int)ret.size(); ++i) {
      int last = S[ret[i].second] - 1;
      int index = upper_bound(S, ret[i].second + 1, last + 1);
      for (int j = index; j < length; ++j) {
        if (last != S[j]) {
          std::vector<int> item(ret[i].first);

          item.push_back(S[j]);
          ret.push_back(std::make_pair(item, j));
        }
        last = S[j];
      }
    }

    std::vector<std::vector<int> > final_ret;

    std::for_each(ret.begin(), ret.end(),
                  [&](std::pair<std::vector<int>, int> &it) {
                    final_ret.push_back(std::move(it.first));
                  });

    return final_ret;
  }

 private:
  int upper_bound(std::vector<int> &S, int begin, int num) {
    int start = begin, end = S.size() - 1;

    while (start < end) {
      int mid = (start + end) >> 1;

      if (S[mid] < num) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }

    return start;
  }
};
