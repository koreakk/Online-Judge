def solution(n: int, m: int, cards: list[int]) -> int:
    answer = 0

    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                curr = cards[i] + cards[j] + cards[k]

                if curr <= m and curr > answer:
                    answer = curr
    return answer

if __name__ == '__main__':    
    n, m = map(int, input().split())
    cards = list(map(int, input().split()))

    print(solution(n, m, cards))