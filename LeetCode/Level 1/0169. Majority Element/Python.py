from typing import List 

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        def mejority_element_rec(low: int, high: int) -> int:
            if low == high:
                return nums[low]
            
            mid = low + (high - low) // 2
            A = mejority_element_rec(low, mid)
            B = mejority_element_rec(mid + 1, high)

            A_count = 0
            for i in range(low, high + 1):
                A_count += (1 if nums[i] == A else 0)

            return A if A_count > mid - low else B

        return mejority_element_rec(0, len(nums) - 1)

if __name__ == '__main__':
    # nums = [2, 2, 1, 1, 1, 2, 2]
    nums = [10,9,9,9,10]
    print(Solution().majorityElement(nums))