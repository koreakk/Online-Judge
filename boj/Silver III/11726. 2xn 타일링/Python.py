def solution(n: int) -> int:
    x, y = 1, 1
    for i in range(n):
        x, y = y, x + y
    
    return x % 10007


if __name__ == '__main__':
    n = int(input())
    print(solution(n))