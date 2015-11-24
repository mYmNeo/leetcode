#include "../config.h"

class BSTIterator {
 public:
  BSTIterator(TreeNode *root) {
    if (!root) {
      node = NULL;
      return;
    }

    node = root;
    while (node->left) {
      parent.push(node);
      node = node->left;
    }
  }

  bool hasNext() {
    if (!node) {
      return false;
    }

    return true;
  }

  int next() {
    int result = node->val;

    if (node->right) {
      node = node->right;
      while (node->left) {
        parent.push(node);
        node = node->left;
      }
    } else {
      if (parent.empty()) {
        node = NULL;
      } else {
        node = parent.top();
        parent.pop();
      }
    }

    return result;
  }

 private:
  std::stack<TreeNode *> parent;
  TreeNode *node;
};
