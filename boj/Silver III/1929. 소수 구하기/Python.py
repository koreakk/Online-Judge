def solution(m: int, n: int) -> list[int]:
    prime = [True] * (n + 1)
    prime[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if prime[i]:
            for j in range(i ** 2, n + 1, i):
                prime[j] = False

    return [i for i in range(m, n + 1) if prime[i]]


if __name__ == '__main__':
    m, n = map(int, input().split())
    print(*solution(m, n), sep='\n')