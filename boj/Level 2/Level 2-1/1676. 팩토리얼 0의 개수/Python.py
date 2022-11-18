def solution(n: int) -> int:
    answer = 0
    n //= 5
    while n:
        answer += n
        n //= 5
    return answer


if __name__ == '__main__':
    n = int(input())
    print(solution(n))