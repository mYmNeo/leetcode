#include "../config.h"

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    return is_valid_bst_helper(root, INT64_MIN, INT64_MAX);
  }

 private:
  bool is_valid_bst_helper(TreeNode *node, int64_t min, int64_t max) {
    if (!node) {
      return true;
    }

    if (node->val <= min || node->val >= max) {
      return false;
    }

    return is_valid_bst_helper(node->left, min, node->val) &&
           is_valid_bst_helper(node->right, node->val, max);
  }
};
