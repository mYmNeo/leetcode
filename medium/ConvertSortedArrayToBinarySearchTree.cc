#include "../config.h"

class Solution
{
public:
    TreeNode *sortedArrayToBST(std::vector<int> &num)
    {
        return sorted_array_to_bst_helper(num, 0, num.size());
    }
private:
    TreeNode *sorted_array_to_bst_helper(std::vector<int> &num, int start, int size)
    {
        if (size == 0) {
            return NULL;
        }

        if (size == 1) {
            return new TreeNode(num[start]);
        }

        TreeNode *mid = new TreeNode(num[start + (size >> 1)]);
        TreeNode *left = sorted_array_to_bst_helper(num, start, size >> 1);
        TreeNode *right = sorted_array_to_bst_helper(num, start + (size >> 1) + 1, (size - 1) >> 1);

        mid->left = left;
        mid->right = right;

        return mid;
    }
};

