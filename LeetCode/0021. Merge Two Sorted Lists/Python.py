from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if (not list1) or (list2 and list1.val > list2.val):
            list1, list2 = list2, list1
        
        if list1:
            list1.next = self.mergeTwoLists(list1.next, list2)
        
        return list1

def makeNode(lst: List[int]) -> Optional[ListNode]:
    res = ptr = ListNode()
    
    for node in lst:
        ptr.next = ListNode(node)
        ptr = ptr.next
    
    return res.next

if __name__ == '__main__':
    S = Solution()
    list1 = makeNode([1, 3, 4])
    list2 = makeNode([1, 2, 4])
    result = S.mergeTwoLists(list1, list2)
    
    while result:
        print(result.val, end=' ')
        result = result.next