def solution(n: int, graph: list[int]) -> list[int]:
    visited = [False] * (n + 1)

    def F(start: int) -> list[int]:
        visited[:] = [False] * (n + 1)
        curr = start

        while not visited[curr]:    
            visited[curr] = True
            curr = graph[curr]
        
        if curr != start: return []
        return [i for i in range(1, n + 1) if visited[i]]

    answer = []
    for i in range(1, n + 1):
        if i in answer: continue
        
        answer.extend(F(i))
    return [len(answer)] + sorted(answer)
            


if __name__ == '__main__':
    n = int(input())
    
    graph = [0] * (n + 1)
    for i in range(1, n + 1):
        graph[i] = int(input())
    
    print(*solution(n, graph), sep='\n')
