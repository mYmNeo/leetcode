#include "../config.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode pivot(0);

        pivot.next = head;
        ListNode *first = &pivot;
        ListNode *end = &pivot;

        while (n--) {
            end = end->next;
        }

        while (end->next) {
            first = first->next;
            end = end->next;
        }

        end = first->next->next;
        first->next = end;

        return pivot.next;
    }
};
