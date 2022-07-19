from sys import stdin


def push(heap: list[int], num: int) -> None:
    heap.append(num)

    childpos = len(heap) - 1
    child = heap[childpos]

    while childpos > 0:
        parentpos = (childpos - 1) // 2
        parent = heap[parentpos]
        if child < parent:
            heap[childpos] = parent
            childpos = parentpos
        else:
            break
    heap[childpos] = child


def pop(heap: list[int]) -> int:
    if not heap:
        return 0
    
    if len(heap) == 1:
        return heap.pop()

    answer = heap[0]
    heap[0] = heap.pop()

    endpos = len(heap)
    parentpos = 0
    childpos = 1
    while childpos < endpos:
        rightpos = childpos + 1
        if rightpos < endpos and heap[childpos] > heap[rightpos]:
            childpos = rightpos
        
        parent = heap[parentpos]
        child = heap[childpos]
        if parent <= child: break

        heap[parentpos], heap[childpos] = child, parent
        parentpos = childpos
        childpos = 2 * parentpos + 1
    
    return answer
    

if __name__ == '__main__':
    n = int(stdin.readline())
    heap= []

    for _ in range(n):
        num = int(stdin.readline())

        if num:
            push(heap, num)
        else:
            print(pop(heap))
