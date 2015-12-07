#include "../config.h"

class Solution {
public:
  std::vector<int> rightSideView(TreeNode *root) {
    std::vector<TreeNode *> list;

    if (!root) {
      return std::vector<int>{};
    }

    std::vector<int> ret;
    list.push_back(root);
    while (!list.empty()) {
      ret.push_back(list.back()->val);

      std::vector<TreeNode *> next;
      for (TreeNode *&it : list) {
        if (it->left) {
          next.push_back(it->left);
        }

        if (it->right) {
          next.push_back(it->right);
        }
      }

      list.swap(next);
    }

    return ret;
  }
};
