#ifdef CONFIG_H
#include "../config.h"
#endif

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
 public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int depth = 0;
    DFS(nestedList, 0, depth);
    int sum = 0;
    DFSCalculator(nestedList, 0, depth, sum);
    return sum;
  }
  void DFS(const vector<NestedInteger>& list, int cur, int& depth) {
    for (auto i : list) {
      if (i.isInteger()) {
        continue;
      }

      DFS(i.getList(), cur + 1, depth);
    }

    depth = max(depth, cur);
  }
  void DFSCalculator(const vector<NestedInteger>& list, int cur, int depth,
                     int& sum) {
    for (auto i : list) {
      if (i.isInteger()) {
        sum += (depth - cur + 1) * i.getInteger();
        continue;
      }

      DFSCalculator(i.getList(), cur + 1, depth, sum);
    }
  }
};

class Solution2 {
 public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
		int unweighted = 0, weigthed = 0;
		while (!nestedList.empty()) {
			vector<NestedInteger> next;
			for (auto i : nestedList) {
				if (i.isInteger()) {
					unweighted += i.getInteger();
					continue;
				}
				auto list = i.getList();
				next.insert(next.end(), list.begin(), list.end());
			}

			weigthed += unweighted;
			nestedList.swap(next);
		}

		return weigthed;
  }
};
