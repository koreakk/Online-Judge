from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        preorder_index = 0
        inorder_index_map = {value: index for index, value in enumerate(inorder)}
        
        def arrayTree(left: int, right: int) -> Optional[TreeNode]:
            nonlocal preorder_index, inorder_index_map
            
            if left > right:
                return None
            
            value = preorder[preorder_index]
            node = TreeNode(value)
            
            preorder_index += 1
            
            node.left = arrayTree(left, inorder_index_map[value] - 1)
            node.right = arrayTree(inorder_index_map[value] + 1, right)
            
            return node
        
        return arrayTree(0, len(preorder) - 1)