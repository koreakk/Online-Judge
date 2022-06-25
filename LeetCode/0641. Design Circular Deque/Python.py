from typing import Optional

class ListNode:  
    def __init__(self, val=0, next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev

class MyCircularDeque:
    def __init__(self, k: int):
        self.head = ListNode()
        self.tail = ListNode()
        self.maxlen = k
        self.len = 0
        self.head.next = self.tail
        self.tail.prev = self.head
        
    def _add(self, node: Optional[ListNode], new: Optional[ListNode]):
        n = node.next
        node.next = new
        new.next, new.prev = n, node
        n.prev = new
    
    def _del(self, node: Optional[ListNode]):
        n = node.next.next
        node.next = n
        n.prev = node
        
    def insertFront(self, value: int) -> bool:
        if self.len == self.maxlen:
            return False
        self.len += 1
        self._add(self.head, ListNode(value))
        return True

    def insertLast(self, value: int) -> bool:
        if self.len == self.maxlen:
            return False
        self.len += 1
        self._add(self.tail.prev, ListNode(value))
        return True

    def deleteFront(self) -> bool:
        if self.len == 0:
            return False
        self.len -= 1
        self._del(self.head)
        return True

    def deleteLast(self) -> bool:
        if self.len == 0:
            return False
        self.len -= 1
        self._del(self.tail.prev.prev)
        return True

    def getFront(self) -> int:
        return self.head.next.val if self.len else -1

    def getRear(self) -> int:
        return self.tail.prev.val if self.len else -1

    def isEmpty(self) -> bool:
        return self.len == 0

    def isFull(self) -> bool:
        return self.len == self.maxlen

# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()