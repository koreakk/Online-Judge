alphabet = list(range(ord('a'), ord('z') + 1))

word = input()
for c in alphabet:
    print(word.find(chr(c)))