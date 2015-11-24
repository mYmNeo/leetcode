#include "../config.h"

class Queue {
 public:
  Queue() { size = 0; }
  void push(int x) {
    ++size;
    frame.push(x);
  }

  void pop(void) {
    std::stack<int> tmp;
    int num = size - 1;
    while (num--) {
      tmp.push(frame.top());
      frame.pop();
    }

    while (!tmp.empty()) {
      frame.push(tmp.top());
      tmp.pop();
    }
    --size;
  }

  int peek(void) {
    std::stack<int> tmp;
    int num = size - 1;
    while (num--) {
      tmp.push(frame.top());
      frame.pop();
    }

    int ret = frame.top();

    while (!tmp.empty()) {
      frame.push(tmp.top());
      tmp.pop();
    }

    return ret;
  }

  bool empty(void) { return size == 0; }

 private:
  int size;
  std::stack<int> frame;
};
