from sys import stdin


def solution(nums: list[int]) -> list[str]:
    stack = list()
    answer = list()
    curr = 1
    
    for num in nums:
        while curr <= num:
            stack.append(curr)
            answer.append('+')
            curr += 1
            
        if stack[-1] == num:
            stack.pop()
            answer.append('-')
        else:
            return ['NO']
    
    return answer


if __name__ == '__main__':
    n = int(stdin.readline())
    nums = [int(stdin.readline()) for _ in range(n)]

    print(*solution(nums), sep='\n')
