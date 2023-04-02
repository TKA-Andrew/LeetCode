class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        farthest = 0

        # no need to jump at the last index
        for i in range(0, n-1):
            farthest = max(farthest, nums[i] + i)
            if (farthest <= i):
                return False

        return farthest >= n - 1
