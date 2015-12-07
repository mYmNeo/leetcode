#include "../config.h"

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    invertTreeHelper(root);
    return root;
  }

private:
  void invertTreeHelper(TreeNode *node) {
    if (!node) {
      return;
    }

    invertTreeHelper(node->left);
    invertTreeHelper(node->right);

    TreeNode *tmp = node->left;
    node->left = node->right;
    node->right = tmp;
  }
};
