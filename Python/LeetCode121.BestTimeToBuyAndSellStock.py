class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        N = (len(prices))
        if N == 1: return 0

        curLowest = prices[0]
        curHighest = 0
        maxProfit = 0

        for i in range(1,N):
            if (prices[i] > curLowest):
                curHighest = prices[i]
                maxProfit = max(maxProfit, curHighest-curLowest)
            elif (curLowest > prices[i]):
                curLowest = prices[i]

        return maxProfit