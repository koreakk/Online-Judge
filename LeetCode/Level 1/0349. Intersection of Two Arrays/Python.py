from typing import List

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        def search(nums: List[int], target: int) -> bool:
            left, right = 0, len(nums) - 1
            
            while left <= right:
                mid = left + (right - left) // 2
                
                if nums[mid] < target:
                    left = mid + 1
                elif nums[mid] > target:
                    right = mid - 1
                else:
                    return True
            return False
            
        result = set()
        nums2.sort()
        for n1 in nums1:
            # Binary Search
            if search(nums2, n1):
                result.add(n1)
                    
        return result
    
if __name__ == "__main__":
    nums1 = [1,2,2,1]
    nums2 = [2,2]
    print(Solution().intersection(nums1, nums2))