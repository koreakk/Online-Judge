from collections import Counter

def solution(word: str) -> str:
    if len(word) <= 1:
        return word.upper()

    c = Counter(word.upper())

    first, second = c.most_common(2)
    return first[0] if first[1] != second[1] else '?'


if __name__ == '__main__':
    word = input()
    print(solution(word))