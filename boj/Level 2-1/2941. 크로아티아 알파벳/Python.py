def solution(word: str) -> int:
    table = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
    
    return len(word) - sum(map(word.count, table))


if __name__ == '__main__':
    word = input()
    print(solution(word))