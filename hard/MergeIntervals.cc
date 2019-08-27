#include "../config.h"

class Solution {
public:
  std::vector<Interval> merge(std::vector<Interval> &intervals) {
    std::vector<Interval> result;

    if (intervals.size() == 0) {
      return result;
    }

    std::sort(
        intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) { return a.start < b.start; });

    std::pair<int, int> cur(intervals.front().start, intervals.front().end);
    for (int i = 1; i < (int)intervals.size(); ++i) {
      if (intervals[i].start <= cur.second) {
        cur.second = std::max(intervals[i].end, cur.second);
      } else {
        result.push_back(Interval(cur.first, cur.second));
        cur.first = intervals[i].start;
        cur.second = intervals[i].end;
      }
    }

    result.push_back(Interval(cur.first, cur.second));

    return result;
  }
};
