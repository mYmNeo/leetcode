#include "../config.h"

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    bool carry = false;

    ListNode pivot(0);
    ListNode *prev = &pivot;

    while (l1 && l2) {
      l1->val = l1->val + l2->val + (carry ? 1 : 0);
      carry = l1->val > 9;
      l1->val %= 10;

      prev->next = l1;
      prev = prev->next;

      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1) {
      l1->val += carry ? 1 : 0;
      carry = l1->val > 9;
      l1->val %= 10;

      prev->next = l1;
      prev = prev->next;

      l1 = l1->next;
    }

    while (l2) {
      l2->val += carry ? 1 : 0;
      carry = l2->val > 9;
      l2->val %= 10;

      prev->next = l2;
      prev = prev->next;

      l2 = l2->next;
    }

    if (carry) {
      prev->next = new ListNode(1);
    }

    return pivot.next;
  }
};
