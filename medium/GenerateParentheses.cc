#include "../config.h"

class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;

    if (n == 0) {
      result.push_back("");
      memory[n] = result;
      return std::move(result);
    }

    if (n == 1) {
      result.push_back("()");
      memory[n] = result;
      return std::move(result);
    }

    if (memory.find(n) != memory.end()) {
      return memory[n];
    }

    for (int i = 1; i <= n; i++) {
      auto left = generateParenthesis(i - 1);
      auto right = generateParenthesis(n - i);

      for (auto &il : left) {
        for (auto &ir : right) {
          result.push_back("(" + il + ")" + ir);
        }
      }
    }

    return memory[n] = result;
  }

private:
  std::unordered_map<int, std::vector<std::string>> memory;
};
