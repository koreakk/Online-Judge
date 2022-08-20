#include <stdio.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool _isSymmetric(struct TreeNode* _Left, struct TreeNode* _Right)
{
    if (_Left == NULL ||  _Right == NULL)
        return _Left == _Right;
    
    return (
        _Left->val == _Right->val &&
        _isSymmetric(_Left->left, _Right->right) &&
        _isSymmetric(_Left->right, _Right->left)
    );

}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL)
        return true;
    return _isSymmetric(root->left, root->right);
}