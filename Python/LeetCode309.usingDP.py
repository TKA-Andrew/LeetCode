class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        N = len(prices)

        if N == 1:
            return 0

        buy = [0] * N
        sell = [0] * N

        buy[0] = -prices[0]
        buy[1] = max(buy[0], sell[0] - prices[1])
        sell[1] = max(sell[0], buy[0] + prices[1])

        for i in range(2, N):
            buy[i] = max(buy[i-1], sell[i-2] - prices[i])
            sell[i] = max(sell[i-1], buy[i-1] + prices[i])
        
        return sell[N-1]