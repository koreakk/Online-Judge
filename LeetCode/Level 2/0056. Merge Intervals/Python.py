from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
        
        for interval in sorted(intervals, key=lambda x: x[0]):
            if merged and interval[0] <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], interval[1])
            else:
                merged.append(interval)
        
        return merged


if __name__ == "__main__":
    intervals = [[1,3],[2,6],[8,10],[15,18]]
    print(Solution().merge(intervals))