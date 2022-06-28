import sys
from collections import deque

def printQueue(N, M, array):
    result = 0
    while True:
        maxValue = max(array)
        firstValue = array.popleft()
        
        if firstValue == maxValue:
            result += 1
            N -= 1
            
            if M == 0:
                return result
        else:
            array.append(firstValue)
        
        M = (M - 1) % N

if __name__ == "__main__":    
    T = int(sys.stdin.readline())
    for _ in range(T):
        N, M = map(int, sys.stdin.readline().split())
        array = deque(map(int, sys.stdin.readline().split()))
        
        print(printQueue(N, M, array))