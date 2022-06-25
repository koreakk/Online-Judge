import heapq
from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        root = result = ListNode() 
        heap = []
        
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(heap, (lists[i].val, i, lists[i]))
        
        while heap:
            node = heapq.heappop(heap)
            result.next = node[2]
            
            result = result.next
            if result.next:
                heapq.heappush(heap, (result.next.val, node[1], result.next))
                
        return root.next

def makeNode(lst: List[int]) -> Optional[ListNode]:
    res = ptr = ListNode()
    
    for node in lst:
        ptr.next = ListNode(node)
        ptr = ptr.next
    
    return res.next

if __name__ == '__main__':
    S = Solution()
    lists = list(map(makeNode, [[1,4,5], [1,3,4], [2,6]]))
    result = S.mergeKLists(lists)
    
    while result:
        print(result.val, end=' -> ')
        result = result.next