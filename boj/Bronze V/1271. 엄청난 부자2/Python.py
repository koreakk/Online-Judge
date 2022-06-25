def solution(n: int, m: int):
    print(n // m)
    print(n % m)

if __name__ == '__main__':
    n, m = map(int, input().split())

    solution(n, m)