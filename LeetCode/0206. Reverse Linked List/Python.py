from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node, prev = head, None
        
        while node:
            prev, prev.next, node = node, prev, node.next
        
        return prev

def makeNode(lst: List[int]) -> Optional[ListNode]:
    res = ptr = ListNode()
    
    for node in lst:
        ptr.next = ListNode(node)
        ptr = ptr.next
    
    return res.next

if __name__ == '__main__':
    S = Solution()
    head = makeNode([1, 2, 3, 4, 5])
    result = S.reverseList(head)
    
    while result:
        print(result.val, end=' ')
        result = result.next