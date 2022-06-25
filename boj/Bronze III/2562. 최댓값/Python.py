max_num = 0
idx = 0

for i in range(1, 10):
    num = int(input())
    
    if max_num < num:
        max_num = num
        idx = i
        
print(max_num)
print(idx)