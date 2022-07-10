def solution(n, info):
    result = -1
    max_score = 0
    cnt_0 = 0
    
    for res in range(1024):
        score = 0
        cnt = n

        for i in range(10):
            if res & (1 << i):
                score += 10 - i
                cnt -= info[i] + 1

            elif info[i]:
                score -= 10 - i


        if cnt >= 0 and max_score < score or \
            (max_score == score and cnt_0 <= cnt):

            result = res
            max_score = score
            cnt_0 = cnt
            
    if result == -1 or max_score == 0:
        return [-1]

    return [info[i] + 1 if result & (1 << i) else 0 for i in range(10)] + [cnt_0]
