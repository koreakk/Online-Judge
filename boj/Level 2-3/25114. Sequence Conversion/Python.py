def solution(n: int, a: list[int], b: list[int]) -> int:
    count = 0
    for i in range(n - 1):
        if a[i] == b[i]:
            continue

        x = a[i] ^ b[i]
        a[i] ^= x
        a[i + 1] ^= x
        count += 1
    
    answer = count if a == b else -1
    return answer

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    print(solution(n, a, b))
