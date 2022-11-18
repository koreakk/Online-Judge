def solution(words: list[str]) -> int:
    def F(word: str) -> int:
        for i in range(len(word) - 1):
            if word[i] != word[i + 1] and word[i] in word[i + 1:]:
                return 0
        return 1

    return sum(map(F, words))


if __name__ == '__main__':
    n = int(input())

    words = list()
    for _ in range(n):
        word = input()
        words.append(word)
    
    print(solution(words))
