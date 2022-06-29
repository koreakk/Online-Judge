def solution(n: int, balls: str) -> int:
    def F(balls: str) -> int:
        for i in range(1, n):
            if balls[i] == balls[i - 1]:
                continue
            
            R = balls[i:].count('R')
            return min(R, len(balls[i:]) - R)
        return 0
    
    answer = min(F(balls), F(balls[::-1]))
    return answer


if __name__ == '__main__':
    n = int(input())
    balls = input()

    print(solution(n, balls))
