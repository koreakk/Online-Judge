from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:  
    def minDiffInBST(self, root: TreeNode) -> int:
        result = float('inf')
        prev = float('-inf')
        
        def dfs(node: Optional[TreeNode]):
            nonlocal result, prev   
            if node:     
                dfs(node.left)
            
                result = min(result, node.val - prev)
                prev = node.val   
            
                dfs(node.right)
    
        dfs(root)
        return result         

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
    print(Solution().minDiffInBST(makeTree([90,69,None,49,89,None,52])))