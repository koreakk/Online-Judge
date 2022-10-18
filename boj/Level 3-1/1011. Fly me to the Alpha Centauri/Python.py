def solution(x: int, y: int) -> int:
    return int((4 * (y - x) - 1) ** (1/2))


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        x, y = map(int, input().split())
        
        print(solution(x, y))
