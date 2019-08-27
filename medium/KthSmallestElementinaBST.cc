#include "../config.h"

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    ans = 0;
    (void)helper(root, k);
    return ans;
  }

private:
  int helper(TreeNode *node, int k) {
    if (!node) {
      return 0;
    }

    int left = helper(node->left, k);
    int right = helper(node->right, k - left - 1);

    if (k == left + 1) {
      ans = node->val;
    }

    return left + right + 1;
  }

private:
  int ans;
};
