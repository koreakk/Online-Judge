from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        isItBalanced = True
        
        def dfs(node: Optional[TreeNode]):
            nonlocal isItBalanced
            
            if node is None:
                return 0
            
            left = dfs(node.left)
            right = dfs(node.right)
            
            if abs(left - right) > 1:
                isItBalanced = False
                
            return max(left, right) + 1
        
        dfs(root)
        return isItBalanced
        
    
def makeTree(lst: List[Optional[int]]) -> Optional[TreeNode]:
    if not lst:
        return None
    
    index = 0
    root = TreeNode(lst[0])
    queue = [root]
    
    while len(lst) > index:
        node = queue.pop(0)
        index += 1
        if len(lst) > index and lst[index] is not None:
            node.left = TreeNode(lst[index])  
            queue.append(node.left)
        index += 1
        if len(lst) > index and lst[index] is not None:
            node.right = TreeNode(lst[index]) 
            queue.append(node.right)
    
    return root
            
if __name__ == '__main__':
    print(Solution().isBalanced(makeTree([1,2,2,3,None,None,3,4,None,None,4])))