#include "../config.h"

class MinStack
{
public:
    void push(int x)
    {
        _data.push(x);

        if (_min.empty() || x <= _min.top()) {
            _min.push(x);
        }
    }

    void pop()
    {
        int d = _data.top();

        if (d == _min.top()) {
            _min.pop();
        }
        _data.pop();
    }

    int top()
    {
        return _data.top();
    }

    int getMin()
    {
        return _min.top();
    }
private:
    std::stack<int> _data;
    std::stack<int> _min;
};

