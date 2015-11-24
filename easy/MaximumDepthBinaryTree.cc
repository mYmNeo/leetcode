#include "../config.h"

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    int depth = 0;

    return max_depth_helper(root, depth);
  }

 private:
  int max_depth_helper(TreeNode *node, int depth) {
    if (!node) {
      return depth;
    }

    int a = max_depth_helper(node->left, depth + 1);
    int b = max_depth_helper(node->right, depth + 1);

    return std::max(a, b);
  }
};
