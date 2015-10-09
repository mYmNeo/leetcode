#include "../config.h"

class Stack
{
  public:
    void push(int x)
    {
      data.push(x);
    }
    void pop()
    {
      int size = data.size() - 1;
      while (size--) {
        data.push(data.front());
        data.pop();
      }

      data.pop();
    }
    int top()
    {
      int size = data.size() - 1;
      while (size--) {
        data.push(data.front());
        data.pop();
      }
      int ret = data.front();
      data.push(ret);
      data.pop();

      return ret;
    }
    bool empty()
    {
      return data.size() == 0;
    }
  private:
    std::queue<int> data;
};

