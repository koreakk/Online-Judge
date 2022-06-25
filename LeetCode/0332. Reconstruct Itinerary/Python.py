import collections
from typing import List

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]: 
        graph = collections.defaultdict(list)
        for key, value in sorted(tickets, reverse=True):
            graph[key].append(value)
            
        route = []
        stack = ['JFK']
        while stack:
            while graph[stack[-1]]:
                stack.append(graph[stack[-1]].pop())
            route.append(stack.pop())
        
        return route[::-1]