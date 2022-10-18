def solution(n: int, scores: int) -> int:
    total_score = sum(scores)
    max_score = max(scores)

    return ((total_score / max_score) * 100) / n


if __name__ == '__main__':
    n = int(input())
    scores = list(map(int, input().split()))

    print(solution(n, scores))
