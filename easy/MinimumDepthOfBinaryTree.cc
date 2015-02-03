#include "config.h"

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root) {
            return 0;
        }

        return min_depth_helper(root, 1);
    }
private:
    int min_depth_helper(TreeNode *node, int cur)
    {
        if (!node->left && !node->right) {
            return cur;
        }

        int left = node->left ? min_depth_helper(node->left, cur + 1) : INT_MAX;
        int right = node->right ? min_depth_helper(node->right, cur + 1) : INT_MAX;

        return std::min(left, right);
    }
};

