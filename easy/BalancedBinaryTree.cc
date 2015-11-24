#include "../config.h"

class Solution {
 public:
  bool isBalanced(TreeNode *root) {
    bool flag = true;

    is_balanced_helper(root, flag);

    return flag;
  }

 private:
  int is_balanced_helper(TreeNode *node, bool &flag) {
    if (!flag || !node) {
      return 0;
    }

    int left = is_balanced_helper(node->left, flag);
    if (!flag) {
      return 0;
    }

    int right = is_balanced_helper(node->right, flag);
    if (!flag) {
      return 0;
    }

    flag = std::abs(left - right) <= 1;

    return std::max(left, right) + 1;
  }
};
