#include "../config.h"

class Solution
{
public:
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        return build_tree_helper(preorder, 0, inorder.size(), inorder);
    }
private:
    TreeNode *build_tree_helper(std::vector<int> &preorder, int si, int ei,
            std::vector<int> &inorder)
    {
        if (ei == si) {
            return NULL;
        }

        int val = preorder.front();
        preorder.erase(preorder.begin());
        TreeNode *root = new TreeNode(val);

        int i;
        for (i = si; i < ei; ++i) {
            if (val != inorder[i]) {
                continue;
            }
            break;
        }
        
        TreeNode *left = build_tree_helper(preorder, si, i, inorder);
        TreeNode *right = build_tree_helper(preorder, i + 1, ei, inorder);
        root->left = left;
        root->right = right;

        return root;
    }
};
