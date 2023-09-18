m = { 136: 1000, 142: 5000, 148: 10000, 154: 50000 }
print(sum(m[list(map(int, input().split()))[0]] for _ in range(int(input()))))