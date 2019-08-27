#include "../config.h"

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head || !head->next) {
      return;
    }

    ListNode *p1 = head, *p2 = head;

    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next->next;
    }

    ListNode *head2 = p1->next;
    p1->next = NULL;
    p2 = head2->next;
    head2->next = NULL;

    while (p2) {
      p1 = p2->next;
      p2->next = head2;
      head2 = p2;
      p2 = p1;
    }

    p1 = head;
    p2 = head2;

    while (p1) {
      ListNode *t = p1->next;
      p1 = p1->next = p2;
      p2 = t;
    }
  }
};
