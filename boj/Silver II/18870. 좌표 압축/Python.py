n = int(input())
nums = list(map(int, input().split()))

table = {
    num: i \
     for i, num in \
        enumerate(sorted(set(nums)))
}

print(*(table[num] for num in nums))