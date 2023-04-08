class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # State: buy or sell or cooldown
        # If buy -> (i+1) cannot buy
        # If sell -> (i+2) including cooldown, (i+2) cannot sell
        # If cooldown -> jump to next step, follow previous state

        dp = {} # key = (i, buy) val = max_profit

        def dfs(i, buying):
            if i >= len(prices):
                return 0
            
            # reuse cache
            if (i, buying) in dp:
                return dp[(i,buying)]
            if buying:
                buy = dfs(i+1, False) - prices[i]
                cooldown = dfs(i+1, True)
                dp[(i, buying)] = max(buy, cooldown)
            else:
                sell = dfs(i+2, True) + prices[i]
                cooldown = dfs(i+1, False)
                dp[(i, buying)] = max(sell, cooldown)
            return dp[(i, buying)]
        
        # start with buy state (or probably cooldown)
        return dfs(0, True)
