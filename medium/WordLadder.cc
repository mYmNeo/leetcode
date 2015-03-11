#include "../config.h"

class Solution
{
public:
    int ladderLength(std::string start, std::string end, std::unordered_set<std::string> &dict)
    {
        std::queue<std::pair<std::string, int> > next;

        dict.insert(start);
        next.push(std::make_pair(start, 1));

        int length = start.length();
        while (!next.empty()) {
            std::string cur = next.front().first;
            int depth = next.front().second;
            next.pop();

            for (int i = 0; i < length; ++i) {
                char origin = cur[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    if (cur[i] == j) {
                        continue;
                    }

                    cur[i] = j;
                    if (cur.compare(end) == 0) {
                        return depth + 1;
                    }

                    if (dict.find(cur) != dict.end()) {
                        dict.erase(cur);
                        next.push(std::make_pair(cur, depth + 1));
                    }
                    cur[i] = origin;
                }
            }
        }

        return 0;
    }
};

