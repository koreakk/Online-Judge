#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode* stack[100];
    int top = -1;

    int* answer = (int*)malloc(sizeof(int) * 100);
    int size = 0;

    struct TreeNode* node = root;
    while (node != NULL)
    {
        for (; node != NULL; node = node->left)
            stack[++top] = node;
        
        do {
            answer[size++] = stack[top]->val;
            node = stack[top--]->right;
        } while (top >= 0 && node == NULL);
    }

    (*returnSize) = size;
    return answer;
}
