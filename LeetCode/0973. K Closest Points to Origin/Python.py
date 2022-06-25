from typing import List

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        return sorted(points, key=lambda point: point[0] ** 2 + point[1] ** 2)[:k]

if __name__ == "__main__":
    points = [[3,3],[5,-1],[-2,4]]
    k = 2
    print(Solution().kClosest(points, k))