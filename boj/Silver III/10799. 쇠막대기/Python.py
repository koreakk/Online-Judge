def solution(string: str) -> int:
    answer, count = 0, 0

    for i in range(len(string)):
        if string[i] == '(':
            count += 1
            continue

        count -= 1
        answer += count if string[i - 1] == '(' else 1
    return answer


if __name__ == '__main__':
    string = input()
    print(solution(string))
