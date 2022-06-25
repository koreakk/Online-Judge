def solution(data: str) -> int:
    table = [
        'ABC', 'DEF', 'GHI',
        'JKL', 'MNO', 'PQRS',
        'TUV', 'WXYZ'
    ]

    answer = 0
    for c in data:
        for i in range(len(table)):
            if c in table[i]:
                answer += i + 3
    return answer


if __name__ == '__main__':
    data = input()
    print(solution(data))