def solution(n: int) -> int:
    x, y = 0, 1
    for _ in range(n):
        x, y = y, x + y
    
    return x


if __name__ == '__main__':
    n = int(input())
    print(solution(n))