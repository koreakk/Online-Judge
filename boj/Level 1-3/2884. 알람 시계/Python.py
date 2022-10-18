def solution(H: int, M: int) -> tuple[int, int]:
    if M >= 45:
        M -= 45
    
    else:
        M += 15
        H = 23 if H == 0 else H - 1
    
    return H, M



if __name__ == '__main__':
    H, M = map(int, input().split())

    print(*solution(H, M))