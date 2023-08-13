for _ in range(int(input())):
    n, s, m, t = map(int, input().split())
    if (s>=10.5 and m>=7.5 and t>=12 and s+m+t>=55):
        print(n, s+m+t, 'PASS')
    else:
        print(n, s+m+t, 'FAIL')