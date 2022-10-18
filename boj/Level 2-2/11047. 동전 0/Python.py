def solution(n: int, k: int, array: list[int]) -> int:
    answer = 0
    for i in range(n - 1, -1, -1):
        answer += k // array[i]
        k %= array[i]

    return answer

if __name__ == '__main__':
    n, k = map(int, input().split())
    array = [int(input()) for _ in range(n)]

    print(solution(n, k, array))