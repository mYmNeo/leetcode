#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
 public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> ve(numCourses);

    for (auto p : prerequisites) {
      ve[p.second].push_back(p.first);
    }
    vector<bool> onpath(numCourses, false), visited(numCourses, false);
    for (int i = 0; i < numCourses; ++i) {
      if (!visited[i] && dfs_cycle(ve, i, onpath, visited)) {
        return false;
      }
    }
    return true;
  }
  bool dfs_cycle(vector<vector<int>>& ve, int node, vector<bool>& onpath,
                 vector<bool>& visited) {
    if (visited[node]) {
      return false;
    }

    onpath[node] = visited[node] = true;
    for (auto neigh : ve[node]) {
      if (onpath[neigh] || dfs_cycle(ve, neigh, onpath, visited)) {
        return true;
      }
    }
    return onpath[node] = false;
  }
};