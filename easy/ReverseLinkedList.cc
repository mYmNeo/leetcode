#include "../config.h"

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr, *cur = nullptr, *next = nullptr;
    if (!head) {
      return NULL;
    }

    cur = head;
    next = cur->next;

    while (next) {
      cur->next = prev;
      prev = cur;
      cur = next;
      next = cur->next;
    }

    cur->next = prev;

    return cur;
  }
};
