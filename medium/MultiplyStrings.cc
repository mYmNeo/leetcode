#include "../config.h"

class Solution {
public:
  std::string multiply(std::string num1, std::string num2) {
    std::string result(num1.length() + num2.length(), '0');
    int carry = 0, digit = 0;

    for (int i = num1.length() - 1; i >= 0; --i) {
      carry = 0;
      for (int j = num2.length() - 1; j >= 0; --j) {
        digit = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') +
                carry;
        result[i + j + 1] = (digit % 10) + '0';
        carry = digit / 10;
      }
      result[i] += carry;
    }

    size_t pos = result.find_first_not_of('0');
    if (pos == std::string::npos) {
      return "0";
    }

    return result.substr(pos);
  }
};
