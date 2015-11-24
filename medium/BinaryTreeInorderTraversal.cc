#include "../config.h"

class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> ret;

    inorder_traversal_helper(root);
    while (!frame.empty()) {
      TreeNode *node = frame.top();
      frame.pop();

      ret.push_back(node->val);
      inorder_traversal_helper(node->right);
    }

    return ret;
  }

 private:
  void inorder_traversal_helper(TreeNode *node) {
    while (node) {
      frame.push(node);
      node = node->left;
    }
  }

 private:
  std::stack<TreeNode *> frame;
};
