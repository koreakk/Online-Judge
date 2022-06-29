def solution(a: int, b: int) -> int:
    while b:
        a, b = b, a % b
    return a


if __name__ == '__main__':
    a, b = map(int, input().split())
    print('1' * solution(a, b))