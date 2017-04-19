#ifdef CONFIG_H
#include "../config.h"
#endif

class Logger {
 public:
  Logger() {}

  bool shouldPrintMessage(int timestamp, string message) {
    if (rec.find(message) == rec.end() || timestamp - rec[message] >= 10) {
      rec[message] = timestamp;
      return true;
    }

    return false;
  }
  unordered_map<string, int> rec;
};
