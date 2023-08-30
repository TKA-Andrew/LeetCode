# Reference: https://www.youtube.com/watch?v=OsPXsE8qhOc

import math

class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        p = len(nums) - 2
        count = 0
        rhs = nums[-1]
        while p >= 0:
            if nums[p] > rhs:
                k = math.ceil(nums[p] / rhs)
                count += k - 1
                rhs = nums[p] // k
            else:
                rhs = nums[p]
            p -= 1
        return count
