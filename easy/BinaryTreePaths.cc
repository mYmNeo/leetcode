#include "../config.h"

class Solution {
 public:
  std::vector<std::string> binaryTreePaths(TreeNode* root) {
    ret.clear();

    std::string path;
    helper(root, path);
    return ret;
  }

 private:
  void helper(TreeNode* node, std::string& path) {
    if (!node) {
      return;
    }

    path.append("->");
    path.append(std::to_string(node->val));
    helper(node->left, path);
    helper(node->right, path);

    if (!node->left && !node->right) {
      ret.push_back(path.substr(2));
    }

    if ((auto pos = path.rfind("->")) != std::string::npos) {
      path = path.substr(0, pos);
    }
  }

 private:
  std::vector<std::string> ret;
};
