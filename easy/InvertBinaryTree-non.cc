#include "../config.h"

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    std::stack<TreeNode*> frame;
    push_left(root, frame);

    while (!frame.empty()) {
      TreeNode* cur = frame.top();
      frame.pop();

      TreeNode* tmp = cur->right;
      cur->right = cur->left;
      cur->left = tmp;

      TreeNode* next = frame.empty() ? nullptr : frame.top();

      if (next && next->left == cur) {
        push_left(next->right, frame);
      }
    }
    return root;
  }

 private:
  void push_left(TreeNode* node, std::stack<TreeNode*>& frame) {
    while (node) {
      frame.push(node);
      node = node->left ? node->left : node->right;
    }
  }
};
