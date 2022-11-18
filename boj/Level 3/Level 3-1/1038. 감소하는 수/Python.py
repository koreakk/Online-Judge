def solution(n: int) -> str:
    answer = '0'
    
    for _ in range(n):
        if answer == '9876543210':
            return '-1'

        size = len(answer)
        idx = 0

        for i in range(1, size):
            if int(answer[i]) + 1 < int(answer[i - 1]):
                idx = i

        if idx == 0 and answer[0] == '9':
            answer = ''.join(map(str, range(size, -1, -1)))

        else:
            answer = answer[:idx] + str(int(answer[idx]) + 1)
            answer += ''.join(map(str, range(size - idx - 2, -1, -1)))
            
    return answer


if __name__ == '__main__':
    n = int(input())
    print(solution(n))