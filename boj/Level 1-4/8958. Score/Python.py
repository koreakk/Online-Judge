def solution(data: str) -> int:
    answer = 0
    curr = 0

    for c in data:
        if c == 'X':
            curr = 0
            continue
        
        curr += 1
        answer += curr

    return answer

T = int(input())
for _ in range(T):
    data = input()
    print(solution(data))