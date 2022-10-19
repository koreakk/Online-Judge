import collections
from typing import List

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"]
        # n = 2
        # A = 6 B = 1 C = 1 D = 1 E = 1 F = 1 G = 1
        # AXX AXX AXX AXX AXX A
        # (n + 1) * (max_count - 1) = AXX AXX AXX AXX AXX = 15
        # max_count_tasks = A = 1
        # output = 15 + 1 = 16
        counts = collections.defaultdict(int)
        for task in tasks:
            counts[task] += 1

        tasks_count = list(counts.values())
        max_count = max(tasks_count)
        max_count_tasks = tasks_count.count(max_count)

        return max((n + 1) * (max_count - 1) + max_count_tasks, len(tasks))
        

if __name__ == '__main__':
    tasks = ["A", "A", "A", "B", "B", "B"]
    n = 2
    print(Solution().leastInterval(tasks, n))