def solution(n: int, arr: list[int]) -> int:
    arr.sort()
    
    result = 0
    for i in range(n):
        result += arr[i] * (n - i)
    return result

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(solution(n, arr))