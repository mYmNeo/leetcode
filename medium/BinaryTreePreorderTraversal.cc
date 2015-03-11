#include "../config.h"

class Solution
{
public:
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        ret.clear();

        preorder_traversal_helper(root);
        while (!frame.empty()) {
            TreeNode *node = frame.top();
            frame.pop();

            preorder_traversal_helper(node);
        }

        return ret;
    }
private:
    void preorder_traversal_helper(TreeNode *node)
    {
        while (node) {
            ret.push_back(node->val);
            if (node->right) {
                frame.push(node->right);
            }
            node = node->left;
        }
    }
private:
    std::stack<TreeNode *> frame;
    std::vector<int> ret;
};

