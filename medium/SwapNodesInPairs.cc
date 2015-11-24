#include "../config.h"

class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    if (!head) {
      return NULL;
    }

    ListNode pivot(0);
    pivot.next = head;
    ListNode *first = &pivot, *second = first;
    int i = 0;

    while (first) {
      i = 0;
      while (i < 2 && second) {
        second = second->next;
        ++i;
      }

      if (!second) {
        break;
      }

      first->next->next = second->next;
      second->next = first->next;
      first->next = second;

      i = 0;
      while (i < 2 && first) {
        first = first->next;
        ++i;
      }
      second = first;
    }

    return pivot.next;
  }
};
