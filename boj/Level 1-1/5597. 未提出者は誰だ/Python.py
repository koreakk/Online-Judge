attendance_table = [False] * 31
for _ in range(28):
    attendance_table[int(input())] = True

for i in range(1, 31):
    if not attendance_table[i]:
        print(i)