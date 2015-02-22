#include "../config.h"

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode pivot(0);
        pivot.next = head;

        head = &pivot;
        ListNode *p, *q, *r;
        for (int i = 1; i < m; ++i) {
            head = head->next;
        }

        p = head->next;
        q = p->next;

        if (!q) {
            return pivot.next;
        }

        r = q->next;

        for (int i = m; i < n; ++i) {
            q->next = p;
            p = q;
            q = r;

            if (!r) {
                break;
            }

            r = r->next;
        }

        head->next->next = q;
        head->next = p;

        return pivot.next;
    }
};

