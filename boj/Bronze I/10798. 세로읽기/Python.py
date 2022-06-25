def solution(words: list[str]) -> None:
    word_max_len = len(max(words, key=len))

    for i in range(word_max_len):
        for j in range(len(words)):
            if len(words[j]) <= i:
                continue
            print(words[j][i], end='')



if __name__ == '__main__':
    words = [input() for _ in range(5)]
    solution(words)