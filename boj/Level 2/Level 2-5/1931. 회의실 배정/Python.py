import sys
from typing import List

def solution(n: int, schedule: List[List[int]]) -> int:
    schedule.sort(key = lambda time: (time[1], time[0]))
    
    end_time = schedule[0][1]
    count = 1
    for i in range(1, n):
        if schedule[i][0] >= end_time:
            count += 1
            end_time = schedule[i][1]
    return count

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    schedule = []
    for i in range(n):
        time = list(map(int, sys.stdin.readline().rstrip().split()))
        schedule.append(time)
        
    print(solution(n, schedule))