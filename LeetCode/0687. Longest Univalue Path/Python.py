from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        self.result = 0
        
        def dfs(node: Optional[TreeNode]):
            if node is None:
                return 0
            
            left = dfs(node.left)
            right = dfs(node.right)
            
            if node.left and node.left.val == node.val:
                left += 1
            else:
                left = 0
            if node.right and node.right.val == node.val:
                right += 1
            else:
                right = 0
                
            self.result = max(self.result, left + right)
            
            return max(left, right)
        
        dfs(root)
        return self.result
            
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
    print(Solution().longestUnivaluePath(makeTree([1,4,5,4,4,5])))