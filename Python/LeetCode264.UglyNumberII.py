class Solution:
    def nthUglyNumber(self, n: int) -> int:
        p2 = 0
        p3 = 0
        p5 = 0

        dp = [0] * n
        dp[0] = 1

        for i in range(1, n):
            p2num = dp[p2] * 2
            p3num = dp[p3] * 3
            p5num = dp[p5] * 5
            minimum = min(p2num, p3num)
            minimum = min(minimum, p5num)
            if minimum == p2num:
                p2 += 1
            if minimum == p3num:
                p3 += 1
            if minimum == p5num:
                p5 += 1
            dp[i] = minimum

        return dp[n-1]