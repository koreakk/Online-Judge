from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = parent = ListNode()
        while head:
            while cur.next and cur.next.val < head.val:
                cur = cur.next
                
            cur.next, head.next, head = head, cur.next, head.next  
                      
            if head and cur.val > head.val:
                cur = parent
        return parent.next
    
def makeNode(lst: List[int]) -> Optional[ListNode]:
    head = prev = ListNode()
    
    for node in lst:
        prev.next = ListNode(node)
        prev = prev.next
    
    return head.next


if __name__ == '__main__':
    head = makeNode([-1,5,3,4,0])
    result = Solution().insertionSortList(head)
    while result:
        print(result.val, end=' ')
        result = result.next