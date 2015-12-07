#include "../config.h"

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (!root) {
      return true;
    }

    return is_symmetric_helper(root->left, root->right);
  }

private:
  bool is_symmetric_helper(TreeNode *left, TreeNode *right) {
    if (!left && !right) {
      return true;
    }

    if (left && !right) {
      return false;
    }

    if (!left && right) {
      return false;
    }

    if (left && right && left->val != right->val) {
      return false;
    }

    if (is_symmetric_helper(left->left, right->right) &&
        is_symmetric_helper(left->right, right->left)) {
      return true;
    }

    return false;
  }
};
