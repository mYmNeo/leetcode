#include "../config.h"

class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL) {
      return false;
    }

    return path_sum_helper(root, root->val, sum);
  }

private:
  bool path_sum_helper(TreeNode *node, int cur, int &sum) {
    if (!node->left && !node->right) {
      return cur == sum ? true : false;
    }

    bool ret = false;
    if (node->left) {
      ret = ret || path_sum_helper(node->left, cur + node->left->val, sum);
    }

    if (!ret && node->right) {
      ret = path_sum_helper(node->right, cur + node->right->val, sum);
    }

    return ret;
  }
};
