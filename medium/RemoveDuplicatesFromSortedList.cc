#include "../config.h"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head, *next = head;
    ListNode pivot(0);
    ListNode *prev = &pivot;

    while (cur) {
      next = cur;
      while (next && cur->val == next->val) {
        next = next->next;
      }

      if (cur->next == next) {
        prev->next = cur;
        prev = prev->next;
      }

      cur = next;
    }

    prev->next = NULL;

    return pivot.next;
  }
};
