def soloution(n: int) -> int:
    answer = 0
    while n >= 0:
        if n % 5 == 0:
            answer += n // 5
            return answer
        n -= 3
        answer += 1

    return -1


if __name__ == '__main__':
    n = int(input())
    print(soloution(n))
