def solution(n: int) -> int:
    x, y = 1, 3
    
    for _ in range(n - 1):
        x, y = y, 2 * x + y

    return x % 10007

if __name__ == '__main__':
    n = int(input())
    print(solution(n))
