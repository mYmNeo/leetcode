#include "../config.h"

class Solution {
public:
  struct _comp {
    bool operator()(const int &a, const int &b) {
      int ab = a * std::pow(10, get_length(b)) + b;
      int ba = b * std::pow(10, get_length(a)) + a;

      if (ab > ba) {
        return true;
      }

      return false;
    }

    int get_length(int n) {
      int l = 0;

      if (n == 0) {
        return 1;
      }

      while (n) {
        l++;
        n /= 10;
      }

      return l;
    }
  };
  std::string largestNumber(std::vector<int> &num) {
    _comp comp;
    std::sort(num.begin(), num.end(), comp);

    std::string result;
    char buffer[20];
    for (auto it = num.begin(); it != num.end(); ++it) {
      std::snprintf(buffer, 20, "%d", *it);
      result.append(buffer);
    }

    int i;
    for (i = 0; i < (int)result.length(); i++) {
      if (result[i] == '0') {
        continue;
      }
      break;
    }

    return i == (int)result.length() ? "0" : result.substr(i);
  }
};
