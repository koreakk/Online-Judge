def solution(k: int, data: list[tuple[int, int]]) -> int:
    _, lengths = zip(*data)

    max_length = max(lengths)
    i = lengths.index(max_length)

    left, right = (i - 1) % 6, (i + 1) % 6
    if lengths[left] < lengths[right]:
        left, right = right, left

    temp = lengths[(left + 3) % 6] * lengths[(i + 3) % 6]
    answer = k * (max_length * lengths[left] - temp)
    return answer


if __name__ == '__main__':
    k = int(input())

    data = list()
    for _ in range(6):
        loc, length = map(int, input().split())
        data.append((loc, length))
    
    print(solution(k, data))
