import re


def solution(pattern: str):
    if re.fullmatch('(100+1+|01)+', pattern):
        print("YES")
    else:
        print('NO')


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        pattern = input()
        solution(pattern)