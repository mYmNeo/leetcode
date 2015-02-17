#include "../config.h"

class Solution
{
public:
    TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
    {
        return build_tree_helper(inorder, 0, inorder.size(), postorder);
    }
private:
    TreeNode *build_tree_helper(std::vector<int> &inorder, int si, int ei,
            std::vector<int> &postorder)
    {
        if (ei == si) {
            return NULL;
        }

        int val = postorder.back();
        postorder.pop_back();
        TreeNode *root = new TreeNode(val);

        int i;
        for (i = si; i < ei; ++i) {
            if (val != inorder[i]) {
                continue;
            }
            break;
        }
        
        TreeNode *right = build_tree_helper(inorder, i + 1, ei, postorder);
        TreeNode *left = build_tree_helper(inorder, si, i, postorder);
        root->left = left;
        root->right = right;

        return root;
    }
};
