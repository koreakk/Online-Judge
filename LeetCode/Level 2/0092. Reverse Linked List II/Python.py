from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
            root = start = ListNode()
            start.next = head
            
            for _ in range(left - 1):
                start = start.next
            end = start.next
            
            for _ in range(right - left):
                tmp, start.next, end.next = start.next, end.next, end.next.next
                start.next.next = tmp         
            
            return root.next
            
def makeNode(lst: List[int]) -> Optional[ListNode]:
    res = ptr = ListNode()
    
    for node in lst:
        ptr.next = ListNode(node)
        ptr = ptr.next
    
    return res.next

if __name__ == '__main__':
    S = Solution()
    head = makeNode([1, 2, 3, 4, 5])
    left = 2
    right = 4
    result = S.reverseBetween(head, left, right)

    while result:
        print(result.val)
        result = result.next