#include <stdio.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX(a, b)   (((a) > (b)) ? (a) : (b))
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    
    int LeftDepth  = maxDepth(root->left);
    int RightDepth = maxDepth(root->right);
    
    return MAX(LeftDepth, RightDepth) + 1;
}
