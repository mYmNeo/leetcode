#include "../config.h"

class Solution {
 public:
  std::vector<int> diffWaysToCompute(std::string input) {
    if (input.empty()) {
      return std::vector<int>{};
    }

    std::vector<int> ret;
    bool only = true;
    for (int i = 0; i < (int)input.length(); ++i) {
      switch (input[i]) {
        case '-':
        case '+':
        case '*': {
          only = false;
          std::vector<int> left = diffWaysToCompute(input.substr(0, i));
          std::vector<int> right =
              diffWaysToCompute(input.substr(i + 1, input.length() - i - 1));

          for (int& l : left) {
            for (int& r : right) {
              switch (input[i]) {
                case '-': {
                  ret.push_back(l - r);
                  break;
                }
                case '+': {
                  ret.push_back(l + r);
                  break;
                }
                case '*': {
                  ret.push_back(l * r);
                  break;
                }
                default: { break; }
              }
            }
          }
          break;
        }
        default: { break; }
      }
    }

    if (only) {
      return std::vector<int>{std::stoi(input)};
    }

    return ret;
  }
};
