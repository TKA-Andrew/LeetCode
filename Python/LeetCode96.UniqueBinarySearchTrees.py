class Solution:
    def numTrees(self, n: int) -> int:
        """
        dp[0] = 1
        dp[1] = 1
        dp[2] = dp[0] * dp[1] + dp[1] * dp[0] = 2
        dp[3] = dp[0] * dp[2] + dp[1] * dp[1] + dp[2] * dp[0]
        """

        dp = [1] * (n+1)
        
        for i in range(2, n+1):
            total = 0
            for j in range(1, i+1):
                left = dp[j-1]
                right = dp[i-j]
                total += (left*right)
            dp[i] = total

        return dp[n]