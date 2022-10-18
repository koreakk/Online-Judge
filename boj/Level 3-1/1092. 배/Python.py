def solution(cranes: list[int], boxs: list[int]) -> int:
    cranes.sort(reverse=True)
    boxs.sort(reverse=True)

    if cranes[0] < boxs[0]:
        return -1

    answer = 0
    while boxs:
        idx = 0
        for crane in cranes:
            while idx < len(boxs) and crane < boxs[idx]:
                idx += 1

            if idx >= len(boxs):
                break
            
            boxs.pop(idx)
        answer += 1

    return answer


if __name__ == '__main__':
    n = int(input())
    cranes = list(map(int, input().split()))
    m = int(input())
    boxs = list(map(int, input().split()))

    print(solution(cranes, boxs))
