from sys import stdin

if __name__ == '__main__':
    n = int(stdin.readline())
    
    nums = []
    for _ in range(n):
        num = int(stdin.readline())
        nums.append(num)

    print(*sorted(nums), sep='\n')