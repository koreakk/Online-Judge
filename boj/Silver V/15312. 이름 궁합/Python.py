def solution(A: str, B: str) -> str:
    numOfStrokes = {
        'A': 3, 'B': 2, 'C': 1, 'D': 2, 'E': 3,
        'F': 3, 'G': 2, 'H': 3, 'I': 3, 'J': 2,
        'K': 2, 'L': 1, 'M': 2, 'N': 2, 'O': 1,
        'P': 2, 'Q': 2, 'R': 2, 'S': 1, 'T': 2,
        'U': 1, 'V': 1, 'W': 1, 'X': 2, 'Y': 2,
        'Z': 1
    }

    answer = list()
    for x, y in zip(A, B):
        answer.append(numOfStrokes[x])
        answer.append(numOfStrokes[y])
    
    while len(answer) > 2:
        answer = [(answer[i] + answer[i+1]) % 10 for i in range(len(answer) - 1)]

    return ''.join(map(str, answer))

if __name__ == '__main__':
    A = input()
    B = input()
    print(solution(A, B))