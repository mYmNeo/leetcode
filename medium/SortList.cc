#include "../config.h"

class Solution {
 public:
  ListNode *sortList(ListNode *head) {
    if (!head) {
      return NULL;
    }

    ListNode *cur = head;
    int length = 0;
    while (cur) {
      length++;
      cur = cur->next;
    }

    return merge_sort(head, length);
  }

 private:
  ListNode *merge_sort(ListNode *head, int length) {
    ListNode pivot(0);
    pivot.next = head;

    if (length == 1) {
      return pivot.next;
    }

    if (length == 2) {
      if (head->val > head->next->val) {
        pivot.next = head->next;
        head->next->next = head;
        head->next = NULL;
      }

      return pivot.next;
    }

    ListNode *new_head = head;
    ListNode *prev = &pivot;
    int new_length = length >> 1;
    int i = new_length;
    while (i--) {
      new_head = new_head->next;
      prev = prev->next;
    }

    prev->next = NULL;

    ListNode *left = merge_sort(pivot.next, new_length);
    ListNode *right = merge_sort(new_head, length - new_length);

    prev = &pivot;

    while (left && right) {
      if (left->val < right->val) {
        prev->next = left;
        left = left->next;
      } else {
        prev->next = right;
        right = right->next;
      }
      prev = prev->next;
    }

    while (left) {
      prev->next = left;
      left = left->next;
      prev = prev->next;
    }

    while (right) {
      prev->next = right;
      right = right->next;
      prev = prev->next;
    }

    return pivot.next;
  }
};
