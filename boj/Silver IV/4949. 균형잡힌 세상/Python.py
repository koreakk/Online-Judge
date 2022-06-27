from sys import stdin

def solution(string: str) -> str:
    bracket = {'(': ')', '[': ']'}
    stack = []   
    
    for c in string:
        if c in '([':
            stack.append(c)
            
        if c in ')]':
            if not stack:
                return 'no'
            
            if bracket[stack.pop()] != c:
                return 'no'
    
    if stack:
        return 'no'
    else:
        return 'yes'

if __name__ == '__main__':
    while True:    
        string = stdin.readline().rstrip()
        if string == '.':
            break
        
        print(solution(string))