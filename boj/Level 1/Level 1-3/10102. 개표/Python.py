input()
r = sum(1 if c == 'A' else -1 for c in input())
if r > 0:
    print('A')
elif r < 0:
    print('B')
else:
    print("Tie")
