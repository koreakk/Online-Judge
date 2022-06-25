def solution(data: list[int]) -> str:
    if data == list(range(1, 9)):
        return 'ascending'

    if data == list(range(8, 0, -1)):
        return 'descending'
    
    return 'mixed'


if __name__ == '__main__':
    data = list(map(int, input().split()))
    print(solution(data))