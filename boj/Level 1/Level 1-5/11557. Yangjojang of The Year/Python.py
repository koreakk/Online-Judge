for _ in range(int(input())):
    cur_s, cur_l = '', 0
    for _ in range(int(input())):
        s, l = input().split()
        l = int(l)

        if (cur_l < l):
            cur_l = l
            cur_s = s

    print(cur_s)
