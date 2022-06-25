def solution(a: int, b: int) -> tuple[int, int]:
    _a, _b = a, b

    while _a % _b:
        _a, _b = _b, _a % _b

    return _b, (a * b) // _b


if __name__ == '__main__':
    a, b = map(int, input().split())
    print(*solution(a, b), sep='\n')