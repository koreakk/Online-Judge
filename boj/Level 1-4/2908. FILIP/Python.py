def solution(a: int, b: int) -> int:
    a_rev = int(str(a)[::-1])
    b_rev = int(str(b)[::-1])

    return max(a_rev, b_rev)

if __name__ == '__main__':
    a, b = map(int, input().split())
    print(solution(a, b))