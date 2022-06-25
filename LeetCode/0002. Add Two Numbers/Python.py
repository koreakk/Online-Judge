from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res = head = ListNode()
        carry = 0
        
        while l1 or l2:
            sum = carry
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next
                
            carry, val = divmod(sum, 10)
            head.next = ListNode(val)
            head = head.next
            
        return res.next
            
def makeNode(lst: List[int]) -> Optional[ListNode]:
    res = ptr = ListNode()
    
    for node in lst:
        ptr.next = ListNode(node)
        ptr = ptr.next
    
    return res.next

if __name__ == '__main__':
    S = Solution()
    l1 = makeNode([1, 2, 3])
    l2 = makeNode([3, 2, 1])
    result = S.addTwoNumbers(l1, l2)
    
    while result:
        print(result.val, end=' ')
        result = result.next