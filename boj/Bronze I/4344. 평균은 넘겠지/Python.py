def solution(n: int, scores: list[int]) -> float:
    mean = sum(scores) / n
    count = sum([1 for score in scores if mean < score])

    answer = (count / n) * 100
    return answer


C = int(input())
for _ in range(C):
    n, *scores = map(int, input().split())
    print(f'{solution(n, scores):.3f}%')