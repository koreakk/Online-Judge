def solution(n: int) -> list[tuple[int, int]]:
    def F(n: int, b: int) -> int:
        answer = 0
        n_base = 1
        while n:
            answer += n % b * n_base
            n //= b
            n_base *= 10

        return answer

    return [(i, m) for i, m in enumerate(map(lambda b: F(n, b), range(2, 11)), 2) \
                if str(m) == str(m)[::-1]]
    

if __name__ == '__main__':
    n = int(input())

    result = solution(n)
    if result:
        for x in result:
            print(*x)
    else:
        print('NIE')