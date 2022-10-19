from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        A, B = nums1, nums2
        if len(A) > len(B):
            A, B = B, A
        
        total = len(A) + len(B)
        half = total // 2

        left, right = 0, len(A) - 1
        while True:
            i = left + (right - left) // 2    # A
            j = half - i - 2                  # B

            A1 = A[i] if i >= 0 else float('-inf')
            A2 = A[i + 1] if (i + 1) < len(A) else float('inf')
            B1 = B[j] if j >= 0 else float('-inf')
            B2 = B[j + 1] if (j + 1) < len(B) else float('inf')

            if A1 > B2:
                right = i - 1
            elif B1 > A2:
                left = i + 1
            else:
                if total % 2 != 0:
                    return min(A2, B2)
                
                return (max(A1, B1) + min(A2, B2)) / 2

if __name__ == '__main__':
    nums1 = [1,2]
    nums2 = [3,4]
    print(Solution().findMedianSortedArrays(nums1, nums2))