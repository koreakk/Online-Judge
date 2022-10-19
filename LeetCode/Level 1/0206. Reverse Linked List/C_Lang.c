#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    
    struct ListNode *Link = NULL;
    struct ListNode *prev = NULL;
    
    while(head) {
        
        Link = head->next;
        head->next = prev;
        prev = head;
        head = Link;
         
    }
    
    return prev;
}