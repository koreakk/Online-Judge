import collections
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        queue = collections.deque([root])
        depth = 0
        
        while queue:
            depth += 1
            
            for _ in range(len(queue)):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        
        return depth
    
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
    root = makeTree([3,9,20,None,None,15,7])
    print(Solution().maxDepth(root))