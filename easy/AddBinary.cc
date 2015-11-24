#include "../config.h"

class Solution {
 public:
  std::string addBinary(std::string &a, std::string &b) {
    std::string result;
    int i, j;

    int num = 0;
    bool carry = false;
    for (i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; i--, j--) {
      num = a[i] - '0' + b[j] - '0' + (carry ? 1 : 0);
      carry = num > 1 ? true : false;
      result.push_back((num % 2) + '0');
    }

    while (i >= 0) {
      num = a[i] - '0' + (carry ? 1 : 0);
      carry = num > 1 ? true : false;
      result.push_back((num % 2) + '0');
      i--;
    }

    while (j >= 0) {
      num = b[j] - '0' + (carry ? 1 : 0);
      carry = num > 1 ? true : false;
      result.push_back((num % 2) + '0');
      j--;
    }

    if (carry) {
      result.push_back('1');
    }

    std::reverse(result.begin(), result.end());

    return result;
  }
};
