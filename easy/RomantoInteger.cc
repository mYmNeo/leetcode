#include "../config.h"

class Solution
{
public:
    Solution()
    {
        _lookup['I'] = 1;
        _lookup['V'] = 5;
        _lookup['X'] = 10;
        _lookup['L'] = 50;
        _lookup['C'] = 100;
        _lookup['D'] = 500;
        _lookup['M'] = 1000;
    }

    int romanToInt(std::string s)
    {
        int num = 0;
        std::stack<int> frame;

        for (int i = 0; i < (int) s.length(); ) {
            int cur = _lookup[s[i]];
            if (frame.empty() || frame.top() < cur) {
                frame.push(cur);
                i++;
            } else {
                num += frame.top();
                frame.pop();

                while (!frame.empty()) {
                    num -= frame.top();
                    frame.pop();
                }
            }
        }

        if (!frame.empty()) {
            num += frame.top();
            frame.pop();

            while (!frame.empty()) {
                num -= frame.top();
                frame.pop();
            }
        }

        return num;
    }
private:
    std::map<char, int> _lookup;
};

