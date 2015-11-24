#include "../config.h"

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) {
      return NULL;
    }

    ListNode *p1 = head, *p2 = head;

    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;

      if (p1 == p2) {
        break;
      }
    }

    if (p1 == p2) {
      p2 = head;

      while (p2 != p1) {
        p1 = p1->next;
        p2 = p2->next;
      }

      return p1;
    }

    return NULL;
  }
};
