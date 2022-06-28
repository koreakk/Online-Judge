import sys

def arithmeticMean(di, N):
    result = round(sum(map(lambda x: x[0] * x[1], di)) / N)
    return result

def median(di, N):
    count = 0
    x = (N // 2) + 1
    
    for i, j in di:
        count += j
        if count >= x:
            return i   

def mode(di):
    di = sorted(di, key=lambda x: x[1], reverse=True)
    
    if len(di) == 1:
        return di[0][0]
    
    result = di[1][0] if di[0][1] == di[1][1] else di[0][0]
    return result
    
def statisticalRange(di):
    result = di[-1][0] - di[0][0]
    return result

if __name__ == '__main__': 
    di = {}
    N = int(sys.stdin.readline())

    for _ in range(N):
        num = int(sys.stdin.readline())
        if num in di:
            di[num] += 1
        else:
            di[num] = 1
            
    di = sorted(di.items())

    print(arithmeticMean(di, N))
    print(median(di, N))
    print(mode(di))
    print(statisticalRange(di))