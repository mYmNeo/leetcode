#include "../config.h"

class Solution
{
public:
    std::vector<std::vector<int> > zigzagLevelOrder(TreeNode *root)
    {
        std::vector<std::vector<int> > result;

        if (!root) {
            return result;
        }

        std::vector<TreeNode *> last {root};
        std::vector<TreeNode *> next;
        std::vector<int> data;
        bool swap = false;

        while (last.size()) {
            data.clear();
            next.clear();
            
            std::for_each(last.begin(), last.end(), [&data, &next](TreeNode *node) {
                    if (node) {
                        data.push_back(node->val);
                        next.push_back(node->left);
                        next.push_back(node->right);
                    }
            });

            if (swap) {
                std::reverse(data.begin(), data.end());
            }

            if (data.size()) {
                result.push_back(data);
            }
            swap = !swap;
            std::swap(last, next);
        }

        return result;
    }
};

