def solution(data: list[tuple[int, int, int]]):
    def F(*n) -> int:
        if len(set(n)) < 3: return 0

        for t, s, b in data:
            target = tuple(map(int, str(t)))
            strike, ball = 0, 0

            for i in range(3):
                if n[i] == target[i]:
                    strike += 1
                elif n[i] in target:
                    ball += 1
            
            if s != strike or b != ball:
                return 0
        return 1

    answer = 0
    for i in range(1, 10):
        for j in range(1, 10):
            for k in range(1, 10):
                answer += F(i, j, k)
    return answer


if __name__ == '__main__':
    n = int(input())
    data = list()
    for _ in range(n):
        t, s, b = map(int, input().split())
        data.append((t, s, b))
    
    print(solution(data))
