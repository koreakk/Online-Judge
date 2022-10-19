from typing import List

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n <= 2:
            return [i for i in range(n)]
        
        graph = [[] for _ in range(n)]
        for start, end in edges:
            graph[start].append(end)
            graph[end].append(start)
        
        leaves = [i for i in range(n) if len(graph[i]) == 1]
        
        remaining_nodes = n
        while remaining_nodes > 2:
            remaining_nodes -= len(leaves)
            new_leaves = []
            for leaf in leaves:
                neighbor = graph[leaf].pop()
                graph[neighbor].remove(leaf)
                
                if len(graph[neighbor]) == 1:
                    new_leaves.append(neighbor)  
                    
            leaves = new_leaves
            
        return leaves