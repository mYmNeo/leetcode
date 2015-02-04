#include "../config.h"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode pivot(0);
        ListNode *cur = &pivot;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                ListNode *item = new ListNode(l1->val);
                cur->next = item;
                cur = item;
                l1 = l1->next;
            } else {
                ListNode *item = new ListNode(l2->val);
                cur->next = item;
                cur = item;
                l2 = l2->next;
            }
        }

        while (l1) {
            ListNode *item = new ListNode(l1->val);
            cur->next = item;
            cur = item;
            l1 = l1->next;
        }

        while (l2) {
            ListNode *item = new ListNode(l2->val);
            cur->next = item;
            cur = item;
            l2 = l2->next;
        }

        return pivot.next;
    }
};

