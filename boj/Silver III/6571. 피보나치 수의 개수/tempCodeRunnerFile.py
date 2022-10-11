def solution(s, e):
    x, y = 1, 2
    count = 0

    while x < e:
        if (s < x and x < e):
            count += 1
        
        x, y = y, x + y
    
    return count

if __name__ == '__main__':
    while True:
        s, e = map(int, input().split())
        if (s == 0 and e == 0):
            break

        print(solution(s, e))
    