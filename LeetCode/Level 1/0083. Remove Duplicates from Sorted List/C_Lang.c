#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* node = head;
    struct ListNode* Next = NULL;
    struct ListNode* temp = NULL;

    for (; node; node = Next)
    {
        Next = node->next;
        while (Next && Next->val == node->val)
        {
            temp = Next;
            Next = Next->next;
            free(temp);
        } 
        node->next = Next;      
    }

    return head;
}