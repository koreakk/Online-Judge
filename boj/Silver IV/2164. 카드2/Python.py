from collections import deque

def solution(n: int):
    cards = deque(range(1, n + 1))

    while len(cards) > 1:
        cards.popleft()
        cards.append(cards.popleft())
    
    return cards[0]


if __name__ == '__main__':
    n = int(input())
    print(solution(n))