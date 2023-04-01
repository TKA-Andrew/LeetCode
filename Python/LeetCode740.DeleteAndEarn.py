class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        # change it to normal dp problem

        n = 10001
        dp = [0]*n

        for num in nums:
            dp[num] += num
        
        for i in range(2, n):
            dp[i] = max(dp[i-1], dp[i-2]+dp[i])

        return dp[n-1]