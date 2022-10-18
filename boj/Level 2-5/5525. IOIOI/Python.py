n = int(input())
length = int(input())
S = input()

answer = 0
idx = 0

while idx < length:
    count = 0

    while idx < length and S[idx: idx + 3] == 'IOI':
        count += 1
        idx += 2

    answer += max(count + 1 - n, 0)
    idx += 1
    
print(answer)