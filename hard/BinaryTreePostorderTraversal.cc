#include "../config.h"

class Solution
{
public:
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        std::stack<TreeNode *> frame;
        std::vector<int> result;
        
        push_left(root, frame);
        while (!frame.empty()) {
            TreeNode *cur = frame.top();
            frame.pop();

            result.push_back(cur->val);

            TreeNode *next = frame.empty() ? NULL : frame.top();

            if (next && next->left == cur) {
                push_left(next->right, frame);
            }
        }

        return result;
    }
private:
    void push_left(TreeNode *node, std::stack<TreeNode *> &frame)
    {
        while (node) {
            frame.push(node);
            node = node->left ? node->left : node->right;
        }
    }
};

