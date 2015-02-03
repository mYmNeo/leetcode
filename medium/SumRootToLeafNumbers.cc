#include "config.h"

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int result = 0;
        
        if (!root) {
            return 0;
        }

        sum_number_helper(root, 0, result);
        
        return result;
    }
private:
    void sum_number_helper(TreeNode *node, int cur, int &result)
    {
        cur *= 10;
        cur += node->val;

        if (!node->left && !node->right) {
            result += cur;
            return;
        }

        if (node->left) {
            sum_number_helper(node->left, cur, result);
        }

        if (node->right) {
            sum_number_helper(node->right, cur, result);
        }
    }
};

