from typing import List

class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        result = []
        for x in sorted(people, key = lambda x: (-x[0], x[1])):
            result.insert(x[1], x)
        return result
    
if __name__ == '__main__':
    people = [[7, 0], [4, 4], [7, 1], [5, 0], [6, 1], [5, 2]]
    # [[5, 0], [7, 0], [5, 2], [6, 1], [4, 4], [7, 1]]
    print(Solution().reconstructQueue(people))