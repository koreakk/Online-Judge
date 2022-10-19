from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        rev = None
        slow = fast = head
        
        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
        if fast:
            slow = slow.next
        
        while rev and rev.val == slow.val:
            rev, slow = rev.next, slow.next
        return not rev
        
def makeNode(lst: List[int]) -> Optional[ListNode]:
    res = ptr = ListNode()
    
    for node in lst:
        ptr.next = ListNode(node)
        ptr = ptr.next
    
    return res.next

if __name__ == '__main__':
    S = Solution()
    head = list(map(int, input().split()))
    head = makeNode(head)
    result = S.isPalindrome(head)
    print(result)