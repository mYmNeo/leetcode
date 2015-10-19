#include "../config.h"

class Solution
{
public:
  bool isPalindrome(ListNode* head)
  {
    if (!head) {
      return true;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode* slow = &dummy, *fast = &dummy;

    while (slow && fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode dummy2(0);
    fast = &dummy2;
    slow = slow->next;

    ListNode *tmp = nullptr;
    while (slow) {
      tmp = slow->next;
      slow->next = fast->next;
      fast->next = slow;
      slow = tmp;
    }

    slow = dummy.next;
    fast = dummy2.next;

    while (slow && fast) {
      if (slow->val == fast->val) {
        slow = slow->next;
        fast = fast->next;
        continue;
      }

      return false;
    }

    return true;
  }
};