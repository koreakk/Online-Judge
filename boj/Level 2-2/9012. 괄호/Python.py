def solution(string: str) -> str:
    count = 0
    for c in string:
        if count == 0 and c == ')':
            return 'NO'
        
        count += 1 if c == '(' else -1
        
    return 'NO' if count else 'YES'


if __name__ == '__main__':
    T = int(input())

    for _ in range(T):
        string = input()
        print(solution(string))