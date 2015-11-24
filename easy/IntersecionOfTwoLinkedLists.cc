#include "../config.h"

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0;
    int lenB = 0;

    ListNode *posA = headA, *posB = headB;

    while (posA) {
      lenA++;
      posA = posA->next;
    }

    while (posB) {
      lenB++;
      posB = posB->next;
    }

    int diff = std::abs(lenA - lenB);
    posA = headA;
    posB = headB;

    if (lenA < lenB) {
      while (diff--) {
        posB = posB->next;
      }
    } else if (lenA > lenB) {
      while (diff--) {
        posA = posA->next;
      }
    }

    while (posA != posB) {
      posA = posA->next;
      posB = posB->next;
    }

    return posA;
  }
};
