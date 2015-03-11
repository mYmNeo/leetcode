#include "../config.h"

class Solution
{
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> data;
        std::queue<UndirectedGraphNode *> next;

        if (!node) {
            return NULL;
        }

        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        data[node] = ret;
        next.push(node);

        while (!next.empty()) {
            UndirectedGraphNode *node = next.front();
            next.pop();

            for (int i = 0; i < (int) node->neighbors.size(); ++i) {
                auto found = data.find(node->neighbors[i]);
                if (found == data.end()) {
                    data[node->neighbors[i]] = new UndirectedGraphNode(node->neighbors[i]->label);
                    data[node]->neighbors.push_back(data[node->neighbors[i]]);
                    next.push(node->neighbors[i]);
                } else {
                    data[node]->neighbors.push_back(found->second);
                }
            }
        }

        return ret;
    }
};
