#include "../config.h"

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head) {
            return NULL;
        }

        ListNode pivot(-1);
        
        ListNode *cur = head, *next = cur->next;
        while (cur) {
            if (!pivot.next) {
                cur->next = NULL;
                pivot.next = cur;
            } else {
                ListNode *pos = pivot.next, *prev = &pivot;
                while (pos) {
                    if (pos->val < cur->val) {
                        pos = pos->next;
                        prev = prev->next;
                    } else {
                        prev->next = cur;
                        cur->next = pos;
                        break;
                    }
                }

                if (!pos) {
                    prev->next = cur;
                    cur->next = NULL;
                }
            }

            cur = next;
            if (cur) {
                next = cur->next;
            }
        }

        return pivot.next;
    }
};

