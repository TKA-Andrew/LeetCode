class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        N = len(prices)
        if N == 1:
            return 0

        s0 = [0] * N
        s1 = [0] * N
        s2 = [0] * N

        s0[0] = 0
        s1[0] = prices[0] * -1
        s2[0] = float('inf') * -1

        for i in range(1, N):
            s0[i] = max(s0[i-1], s2[i-1])
            s1[i] = max(s1[i-1], s0[i-1] - prices[i])
            s2[i] = s1[i-1] + prices[i]

        return max(max(s0), max(s2))