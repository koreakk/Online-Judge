from typing import Optional, List
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root == None:
            return []

        answer = []
        q = deque([root])

        while q:
            length = len(q)

            for i in range(length):
                if q[i].left:
                    q.append(q[i].left)
                if q[i].right:
                    q.append(q[i].right)
            
            answer.append([q.popleft().val for _ in range(length)])

        return answer
