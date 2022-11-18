def solution(N: int, P: int) -> int:
    array = []
    first = N

    def next(first: int, N: int, P: int) -> int:
        return first * N % P

    while N not in array:
        array.append(N)
        N = next(first, N, P) 

    return len(array[array.index(N):])


if __name__ == '__main__':
    N, P = map(int, input().split())
        
    print(solution(N, P))