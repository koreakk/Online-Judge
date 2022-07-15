def solution(n: int, P: list[int], S: list[int]) -> int:
    def F():
        for i in range(n):
            if i % 3 != P[i]:
                return True
        return False

    first_P = P[:]
    answer = 0
    while F():
        answer += 1
        for i, player in enumerate(P[:]):
            P[S[i]] = player

        if P == first_P:
            return -1

    return answer


if __name__ == '__main__':
    n = int(input())
    P = list(map(int, input().split()))
    S = list(map(int, input().split()))

    print(solution(n, P, S))