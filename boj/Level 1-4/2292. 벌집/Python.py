n = int(input())

answer = 1
total = 1
while n > total:
    total += answer * 6
    answer += 1

print(answer)