#include "../config.h"

class Solution {
 public:
  int evalRPN(std::vector<std::string> &tokens) {
    if (tokens.empty()) {
      return 0;
    }

    std::stack<int> frame;
    for (std::string &item : tokens) {
      switch (item.front()) {
        case '+': {
          if (item.length() == 1) {
            int second = frame.top();
            frame.pop();
            int first = frame.top();
            frame.pop();

            frame.push(first + second);
          } else {
            frame.push(::atoi(item.c_str()));
          }
          break;
        }
        case '-': {
          if (item.length() == 1) {
            int second = frame.top();
            frame.pop();
            int first = frame.top();
            frame.pop();

            frame.push(first - second);
          } else {
            frame.push(::atoi(item.c_str()));
          }
          break;
        }
        case '*': {
          int second = frame.top();
          frame.pop();
          int first = frame.top();
          frame.pop();

          frame.push(first * second);
          break;
        }
        case '/': {
          int second = frame.top();
          frame.pop();
          int first = frame.top();
          frame.pop();

          frame.push(first / second);
          break;
        }
        default: {
          frame.push(::atoi(item.c_str()));
          break;
        }
      }
    }

    return frame.top();
  }
};
