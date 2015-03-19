#include "../config.h"

class Solution
{
public:
    std::vector<Interval> insert(std::vector<Interval> &intervals, Interval newInterval)
    {
        intervals.push_back(newInterval);
        std::sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });
        
        if (intervals.size() == 1) {
            return intervals;
        }

        Interval last(intervals.front().start, intervals.front().end);
        std::vector<Interval> ret;

        for (int i = 1; i < (int) intervals.size(); ++i) {
            if (last.end >= intervals[i].start) {
                last.end = std::max(last.end, intervals[i].end);
            } else {
                ret.push_back(last);
                last.start = intervals[i].start;
                last.end = intervals[i].end;
            }
        }

        ret.push_back(last);

        return ret;
    }
};

