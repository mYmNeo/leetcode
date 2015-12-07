#include "../config.h"

class Solution {
public:
  int atoi(const char *str) {
    int64_t num = 0;
    bool negative = false;

    const char *start = str;

    if (!str) {
      return num;
    }

    start = str;
    while (*start && *start <= ' ') {
      start++;
    }

    if (*start == '+') {
      negative = false;
      start++;
    } else if (*start == '-') {
      negative = true;
      start++;
    } else if (!is_number(*start)) {
      return num;
    }

    int count = 0;
    while (*start && is_number(*start) && count <= 10) {
      num *= 10;
      num += *start - '0';
      start++;
      count++;
    }

    if (negative) {
      num = -num;
    }

    if (num > INT_MAX) {
      return INT_MAX;
    } else if (num < INT_MIN) {
      return INT_MIN;
    }

    return num;
  }

private:
  inline bool is_number(char c) { return c >= '0' && c <= '9' ? true : false; }
};
