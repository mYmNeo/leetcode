#include "../config.h"

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0) {
            return head;
        }

        int length = 1;
        ListNode *pos = head;
        while (pos->next) {
            ++length;
            pos = pos->next;
        }

        k = k % length;
        if (k == 0) {
            return head;
        }

        k = length - k;

        pos->next = head;
        pos = head;
        while (--k) {
            pos = pos->next;
        }
        
        head = pos->next;
        pos->next = NULL;

        return head;
    }
};

