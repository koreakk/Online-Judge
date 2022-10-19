from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        
        odd = head
        even = head.next
        even_head = head.next
        
        while even and even.next:
            head.next, even.next = head.next.next, even.next.next
            head, even = head.next, even.next
        
        head.next = even_head
        return odd                   
        
def makeNode(lst: List[int]) -> Optional[ListNode]:
    res = ptr = ListNode()
    
    for node in lst:
        ptr.next = ListNode(node)
        ptr = ptr.next
    
    return res.next

if __name__ == '__main__':
    S = Solution()
    head = makeNode([1, 2, 3, 4, 5])
    result = S.oddEvenList(head)
    
    while result:
        print(result.val)
        result = result.next