#include "../config.h"

class Solution {
 public:
  void flatten(TreeNode *root) {
    if (!root) {
      return;
    }

    std::stack<TreeNode *> frame;
    TreeNode *tail = root;
    TreeNode *node = root;

    do {
      if (!node) {
        node = frame.top();
        frame.pop();
        if (node) {
          tail->left = node;
          tail = node;
        }
      }

      while (node) {
        frame.push(node->right);
        tail = node;
        node = node->left;
      }
    } while (!frame.empty());

    node = root;
    while (node) {
      TreeNode *next = node->left;
      node->right = node->left;
      node->left = NULL;
      node = next;
    }
  }
};
