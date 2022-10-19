from typing import Optional, List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
      
      
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not (head and head.next):
            return head
                   
        slow, fast = head, head.next
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        left, right, slow.next = head, slow.next, None
        left = self.sortList(left)
        right = self.sortList(right)
        
        root = prev = ListNode()
        while left and right:
            if left.val > right.val:
                prev.next = right
                right = right.next
            else:
                prev.next = left
                left = left.next
            prev = prev.next
        if left:
            prev.next = left
        if right:
            prev.next = right
            
        return root.next
     
                
def makeNode(lst: List[int]) -> Optional[ListNode]:
    head = prev = ListNode()
    
    for node in lst:
        prev.next = ListNode(node)
        prev = prev.next
    
    return head.next


if __name__ == '__main__':
    result = Solution().sortList(makeNode([-1,5,3,4,0]))
    while result:
        print(result.val, end=' ')
        result = result.next