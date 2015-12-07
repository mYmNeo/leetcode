#include "../config.h"

class Solution {
public:
  std::vector<TreeNode *> generateTrees(int n) {
    return generate_trees_helper(1, n);
  }

private:
  std::vector<TreeNode *> generate_trees_helper(int s, int e) {
    std::vector<TreeNode *> res;
    if (s > e) {
      res.push_back(NULL);
      return res;
    }

    for (int i = s; i <= e; ++i) {
      std::vector<TreeNode *> left_trees = generate_trees_helper(s, i - 1);
      std::vector<TreeNode *> right_trees = generate_trees_helper(i + 1, e);

      for (TreeNode *&left : left_trees) {
        for (TreeNode *&right : right_trees) {
          TreeNode *root = new TreeNode(i);
          root->left = left;
          root->right = right;
          res.push_back(root);
        }
      }
    }

    return res;
  }
};
