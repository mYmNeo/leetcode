#include "config.h"

class Solution
{
public:
    std::vector<std::vector<int> > levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int> > ret;
        std::vector<TreeNode *> cur, next;

        if (!root) {
            return ret;
        }

        cur.push_back(root);

        while (!cur.empty()) {
            std::vector<int> item;

            next.clear();
            for (auto it = cur.begin(); it != cur.end(); ++it) {
                item.push_back((*it)->val);
                if ((*it)->left) {
                    next.push_back((*it)->left);
                }

                if ((*it)->right) {
                    next.push_back((*it)->right);
                }
            }

            ret.push_back(item);
            cur.swap(next);
        }

        return ret;
    }
};
