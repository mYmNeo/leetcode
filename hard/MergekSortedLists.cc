#include "../config.h"

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }
    while (lists.size() > 1) {
      lists.push_back(mergeLists(lists[0], lists[1]));
      lists.erase(lists.begin());
      lists.erase(lists.begin());
    }

    return lists.front();
  }
  ListNode *mergeLists(ListNode *l1, ListNode *l2) {
    ListNode pivot(0);
    ListNode *next = &pivot;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        next->next = l1;
        next = next->next;
        l1 = l1->next;
      } else {
        next->next = l2;
        next = next->next;
        l2 = l2->next;
      }
    }

    if (l1) {
      next->next = l1;
    }

    if (l2) {
      next->next = l2;
    }

    return pivot.next;
  }
};
