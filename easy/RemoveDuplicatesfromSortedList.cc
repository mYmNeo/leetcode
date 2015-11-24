#include "../config.h"

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode pivot(0);
    pivot.next = head;

    ListNode *last = head;

    head = head->next;
    while (head) {
      if (head->val == last->val) {
        head = head->next;
        continue;
      }
      last->next = head;
      last = head;
      head = head->next;
    }

    last->next = NULL;

    return pivot.next;
  }
};
