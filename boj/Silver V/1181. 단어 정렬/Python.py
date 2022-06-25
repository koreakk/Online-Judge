words = set()
n = int(input())

for _ in range(n):
    word = input()
    words.add(word)

print(*sorted(words, key=lambda x: (len(x), x)), sep='\n')