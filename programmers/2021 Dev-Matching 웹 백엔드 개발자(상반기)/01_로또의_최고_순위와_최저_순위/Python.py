def solution(lottos, win_nums):

    rank = [6, 6, 5, 4, 3, 2, 1]

    cnt_0 = lottos.count(0)
    ans = sum(x in lottos for x in win_nums)
    
    return rank[ans + cnt_0], rank[ans]
