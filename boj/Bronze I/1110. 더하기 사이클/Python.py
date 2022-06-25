def solution(n: int) -> int:
    first = n

    answer = 0
    while True:
        n = n%10 * 10 + ((n//10 + n%10) % 10)
        answer += 1
        
        if first == n:
            return answer

if __name__ == '__main__':
    n = int(input())
    print(solution(n))