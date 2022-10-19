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
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    struct TreeNode* stack[100];
    int top = -1;

    int* answer = (int*)malloc(sizeof(int) * 100);
    int size = 0;

    struct TreeNode* node = root;
    while (node != NULL)
    {
        for (; node != NULL; node = node->right) {
            stack[++top] = node;
            answer[size++] = node->val;
        }

        node = stack[top--]->left;
        while (top >= 0 && node == NULL)
            node = stack[top--]->left;
    }

    // reverse
    int l = 0, r = size - 1;
    int temp = 0;

#define SWAP(a, b)  ((temp) = (a), (a) = (b), (b) = (temp))
    while (l < r)
    {
        SWAP(answer[l], answer[r]);
        l++, r--;
    }

    (*returnSize) = size;
    return answer;
}
