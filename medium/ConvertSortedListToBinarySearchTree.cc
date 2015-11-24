#include "../config.h"

class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) {
      return NULL;
    }

    int num = 0;
    ListNode *node = head;
    do {
      num++;
      node = node->next;
    } while (node);

    return sorted_list_to_bst_helper(head, num);
  }

 private:
  TreeNode *sorted_list_to_bst_helper(ListNode *head, int num) {
    if (num == 0) {
      return NULL;
    }

    if (num == 1) {
      return new TreeNode(head->val);
    }

    int mid = num >> 1;
    if (num % 2) {
      ++mid;
    }

    ListNode *node = head;
    for (int i = 1; i < mid; ++i) {
      node = node->next;
    }

    TreeNode *mid_node = new TreeNode(node->val);
    TreeNode *right = sorted_list_to_bst_helper(node->next, num - mid);
    node->next = NULL;
    TreeNode *left = sorted_list_to_bst_helper(head, mid - 1);

    mid_node->left = left;
    mid_node->right = right;

    return mid_node;
  }
};
