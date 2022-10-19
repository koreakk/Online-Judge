#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

#define MAX(a, b)   (((a) > (b)) ? (a) : (b))
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int LeftDepth = maxDepth(root->left);
    int RightDepth = maxDepth(root->right);

    return MAX(LeftDepth, RightDepth) + 1;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        (*returnSize) = 0;
        return NULL;
    }

    int depth = maxDepth(root);

    (*returnSize) = depth;
    int** answer = (int**)malloc(sizeof(int*) * depth);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * depth);

    struct TreeNode* queue[10000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    for (int level = 0; front < rear && level < depth; level++) {
        int length = rear - front;

        for (int i = front; i < length + front; i++) {
            if (queue[i]->left)
                queue[rear++] = queue[i]->left;
            if (queue[i]->right)
                queue[rear++] = queue[i]->right;
        }

        answer[level] = (int*)malloc(sizeof(int) * length);
        (*returnColumnSizes)[level] = length;

        for (int i = 0; i < length; i++)
            answer[level][i] = queue[front++]->val;
    }

    return answer;
}