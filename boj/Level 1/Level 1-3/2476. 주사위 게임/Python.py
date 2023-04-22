N = int(input())

max_score = 0
for _ in range(N):
    A1, A2, A3 = map(int, input().split())
    score = 0

    if (A1 == A2 == A3):
        score = 10000 + A1 * 1000
    elif (A1 == A2 or A1 == A3):
        score = 1000 + A1 * 100
    elif (A2 == A3):
        score = 1000 + A2 * 100
    else:
        score = max(A1, A2, A3) * 100

    max_score = max(max_score, score)

print(max_score)
