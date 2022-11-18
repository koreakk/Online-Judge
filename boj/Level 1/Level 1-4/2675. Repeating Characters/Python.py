T = int(input())
for _ in range(T):
    R, S = input().split()

    answer = map(lambda x: x * int(R), S)
    print(''.join(answer))