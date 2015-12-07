#include "../config.h"

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root) {
      return;
    }

    root->next = NULL;
    while (root) {
      TreeLinkNode *copy = root;
      TreeLinkNode *last = NULL;

      while (copy && copy->left) {
        if (last) {
          last->next = copy->left;
        }
        copy->left->next = copy->right;
        last = copy->right;
        copy = copy->next;
      }

      root = root->left;
    }
  }
};
