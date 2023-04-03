class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        N = len(nums)

        if N == 1: return nums[0]

        dp = [0] * N
        dp[0] = nums[0]
        dp[1] = max(nums[1], dp[0] + nums[1])

        for i in range(2, N):
            dp[i] = max(nums[i], dp[i-1] + nums[i])
        
        maxSub = dp[0]
        
        for x in dp:
            maxSub = max(x, maxSub)
        
        return maxSub