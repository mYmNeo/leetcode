#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
    if (n == 1) {
      return vector<int>{0};
    }
    vector<unordered_set<int>> graph(n);
    for (auto e : edges) {
      graph[e.first].insert(e.second);
      graph[e.second].insert(e.first);
    }

    vector<int> candidate;
    for (int i = 0; i < n; ++i) {
      if (graph[i].size() == 1) {
        candidate.push_back(i);
      }
    }

    while (n > 2) {
      n -= candidate.size();
      vector<int> next;
      for (auto v : candidate) {
        for (auto i : graph[v]) {
          graph[i].erase(v);
          if (graph[i].size() == 1) {
            next.push_back(i);
          }
        }
      }
      candidate.swap(next);
    }

    return candidate;
  }
};
