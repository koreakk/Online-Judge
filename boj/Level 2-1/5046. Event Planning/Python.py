def solution(n: int, b: int, h: int, w: int, cost: list[int], personnel: list[list[int]]) -> int:
    answer = 0
    for i in range(h):
        total_cost = n * cost[i]

        if total_cost <= b and n <= max(personnel[i]):
            answer = min(answer, total_cost) if answer else total_cost
    
    return answer

if __name__ == '__main__':
    n, b, h, w = map(int, input().split())
    cost = list()
    personnel = list()

    for i in range(h):
        cost.append(int(input()))
        personnel.append(list(map(int, input().split())))
    
    result = solution(n, b, h, w, cost, personnel)
    print(result if result else 'stay home')
