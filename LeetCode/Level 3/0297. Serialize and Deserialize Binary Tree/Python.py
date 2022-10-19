import collections
from typing import Optional

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:
    def serialize(self, root: Optional[TreeNode]) -> str:
        data = []
        queue = collections.deque([root])
        
        while queue:
            node = queue.popleft()   
            if node:
                queue.extend([node.left, node.right])
                
                data.append(str(node.val))
            else:
                data.append('null')
        return ' '.join(data)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        if data == 'null':
            return None
        
        nodes = data.split()
        
        index = 0
        root = TreeNode(int(nodes[index]))
        queue = collections.deque([root])
        
        while queue:
            node = queue.popleft()
            
            index += 1
            if nodes[index] != 'null':
                node.left = TreeNode(int(nodes[index]))
                queue.append(node.left)
            
            index += 1
            if nodes[index] != 'null':
                node.right = TreeNode(int(nodes[index]))
                queue.append(node.right)
        return root
            
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))