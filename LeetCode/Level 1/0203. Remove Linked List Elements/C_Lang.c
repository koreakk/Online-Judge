#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
        return NULL;

    if (head->val == val) {
        struct ListNode* del = head;
        head = head->next;

        free(del);

        return removeElements(head, val);
    }
    
    head->next = removeElements(head->next, val);

    return head;
}