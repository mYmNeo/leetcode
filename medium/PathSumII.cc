#include "../config.h"

class Solution {
 private:
  struct param_t {
    int sum;
    TreeNode *node;
    std::vector<int> path;

    param_t(int s, TreeNode *n, std::vector<int> &p)
        : sum(s), node(n), path(p) {}
    param_t(int s, TreeNode *n) : sum(s), node(n) {}
  };

 public:
  std::vector<std::vector<int> > pathSum(TreeNode *root, int sum) {
    std::vector<std::vector<int> > result;

    if (!root) {
      return result;
    }

    std::deque<param_t> next;

    next.push_back(param_t(0, root));

    while (!next.empty()) {
      param_t cur = std::move(next.front());
      next.pop_front();

      cur.sum += cur.node->val;
      cur.path.push_back(cur.node->val);

      if (!cur.node->left && !cur.node->right) {
        if (cur.sum == sum) {
          result.push_back(cur.path);
        }
        continue;
      }

      if (cur.node->left) {
        next.push_back(param_t(cur.sum, cur.node->left, cur.path));
      }

      if (cur.node->right) {
        next.push_back(param_t(cur.sum, cur.node->right, cur.path));
      }
    }

    return result;
  }
};
