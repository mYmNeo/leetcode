#include "../config.h"

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode less(0), more(0);
        ListNode *less_ptr = &less, *more_ptr = &more;

        while (head) {
            if (head->val < x) {
                less_ptr->next = head;
                less_ptr = less_ptr->next;
            } else {
                more_ptr->next = head;
                more_ptr = more_ptr->next;
            }

            head = head->next;
        }

        more_ptr->next = NULL;
        less_ptr->next = more_ptr->next;

        return less.next;
    }
};

