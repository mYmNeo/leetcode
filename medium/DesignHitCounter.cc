#ifdef CONFIG_H
#include "../config.h"
#endif

class HitCounter {
 public:
  /** Initialize your data structure here. */
  HitCounter() {
    fill(begin(hits), end(hits), 0);
    fill(begin(last), end(last), 0);
  }
  /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
  void hit(int timestamp) {
    int index = timestamp % 300;
    if (last[index] != timestamp) {
      last[index] = timestamp;
      hits[index] = 1;
    } else {
      ++hits[index];
    }
  }

  /** Return the number of hits in the past 5 minutes.
      @param timestamp - The current timestamp (in seconds granularity). */
  int getHits(int timestamp) {
    int total = 0;
    for (int i = 0; i < 300; ++i) {
      if (timestamp - last[i] < 300) {
        total += hits[i];
      }
    }

    return total;
  }

  int hits[300];
  int last[300];
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
