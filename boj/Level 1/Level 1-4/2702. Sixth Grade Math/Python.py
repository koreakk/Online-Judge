def solution(a: int, b: int) -> tuple[int, int]:
    _a, _b = a, b

    while _a % _b:
        _a, _b = _b, _a % _b

    return (a * b) // _b, _b


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        a, b = map(int, input().split())

        print(*solution(a, b))