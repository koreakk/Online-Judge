#include <stdio.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root == NULL)
        return false;
    
    int nextTargetSum = targetSum - root->val;

    // leaf node
    if (root->left == NULL && root->right == NULL)
        return nextTargetSum == 0;
        
    return (
        hasPathSum(root->left, nextTargetSum) ||
        hasPathSum(root->right, nextTargetSum)
    );
}