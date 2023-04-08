class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        N = len(prices)

        buy = [0] * N
        sell = [0] * N

        buy[0] = -prices[0]
        
        for i in range(1, N):
            buy[i] = max(buy[i-1], sell[i-1] - prices[i])
            sell[i] = max(sell[i-1], buy[i-1] + prices[i] - fee)
        
        return sell[N-1]