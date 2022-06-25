def solution(L: int, string: str) -> int:
    r = 31
    M = 1234567891

    H = 0
    for i in range(L):
        H += (ord(string[i]) - 96) * (r ** i)

    return H % M


if __name__ == '__main__':
    L = int(input())
    string = input()

    print(solution(L, string))