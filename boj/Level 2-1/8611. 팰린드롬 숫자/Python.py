def solution(n: int) -> list[tuple[int, int]]:
    def F(n: int, b: int) -> int:
        answer = 0
        n_base = 1
        while n:
            answer += n % b * n_base
            n //= b
            n_base *= 10

        return answer

    conversion = map(lambda b: (b, F(n, b)), range(2, 11))
    palindrome = lambda x: str(x[1]) == str(x[1])[::-1]

    return list(filter(palindrome, conversion))
    

if __name__ == '__main__':
    n = int(input())

    result = solution(n)
    if result:
        for x in result:
            print(*x)
    else:
        print('NIE')