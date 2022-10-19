import collections

class ListNode:
    def __init__(self, key=None, value=None):
        self.key = key
        self.value = value
        self.next = None

class MyHashMap:
    def __init__(self):
        self.size = 1000
        self.table = collections.defaultdict(ListNode)
        
    def put(self, key: int, value: int) -> None:
        index = key % self.size
        if self.table[index].value is None:
            self.table[index] = ListNode(key, value)
            return
        
        point = self.table[index]
        while True:
            if point.key == key:
                point.value = value
                return
            if point.next is None:
                break
            point = point.next
        point.next = ListNode(key, value)

    def get(self, key: int) -> int:
        index = key % self.size
        if self.table[index].value is None:
            return -1
        
        point = self.table[index]
        while point:
            if point.key == key:
                return point.value
            point = point.next
        return -1

    def remove(self, key: int) -> None:
        index = key % self.size
        if self.table[index].value is None:
            return
        
        point = self.table[index]
        if point.key == key:
            self.table[index] = ListNode() if point.next is None else point.next
            return
        
        while point.next:
            if point.next.key == key:
                point.next = None if point.next.next is None else point.next.next
                return
            point = point.next


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)