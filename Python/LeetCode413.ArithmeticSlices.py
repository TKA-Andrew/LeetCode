class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 1 or N == 2: return 0
        dp = [0] * N

        for i in range(2, N):
            if nums[i] - nums[i-1] == nums[i-1] - nums[i-2]:
                dp[i] = dp[i-1] + 1
        
        return sum(dp)
