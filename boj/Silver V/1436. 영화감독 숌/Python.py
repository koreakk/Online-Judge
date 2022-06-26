def solution(n: int) -> int: 
    answer = 0

    for i in range(n):
        answer += 1
        while '666' not in str(answer):
            answer += 1
    
    return answer


if __name__ == '__main__':
    n = int(input())
    print(solution(n))
