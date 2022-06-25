def solution(n: int) -> str:
    return 'yes' if str(n) == str(n)[::-1] else 'no'

if __name__ == '__main__':
    while True:
        n = int(input())
        if not n: break
        
        print(solution(n))