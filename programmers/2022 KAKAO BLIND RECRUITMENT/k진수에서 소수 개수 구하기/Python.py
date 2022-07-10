def conversion(n, k):
    if n < (k-1):
        return str(n)
    
    return conversion(n // k, k) + str(n % k)

def isPrime(n):
    if n < 2:
        return False
    
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def solution(n, k):
    answer = sum(isPrime(int(x)) for x in conversion(n, k).split('0') if x.isdigit())
    return answer