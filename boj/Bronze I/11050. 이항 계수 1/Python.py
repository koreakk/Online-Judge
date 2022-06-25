def solution(n: int, k: int) -> int:
    def factorial(n: int) -> int:
        if n <= 1:
            return 1
        
        return n * factorial(n - 1)
    
    return factorial(n) // ((factorial(k)) * factorial(n - k))


if __name__ == '__main__':
    n, k = map(int, input().split())
    print(solution(n, k))