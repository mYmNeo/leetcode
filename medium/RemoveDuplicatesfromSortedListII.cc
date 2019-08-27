#ifdef CONFIG_H
#include "../config.h"
#endif

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** pos = &head;
        ListNode* check = *pos;
        int count = 0;
        
        while (check) {
            if (check->val == (*pos)->val) {
                ++count;
                check = check->next;
                continue;
            }
            
            if (count == 1) {
                pos = &(*pos)->next;
            } else {
                *pos = check;
            }
            count = 0;
        }
        
        if (count > 1) {
            *pos = check;
        }
        return head;
    }
};