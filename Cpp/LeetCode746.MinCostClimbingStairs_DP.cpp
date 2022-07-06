#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        
        if (n==0) return 0;
        if (n==1) return cost[0];
        if (n==2) return std::min(cost[0], cost[1]);
        
        // dp[i] means the minimum cost to reach ith level
        std::vector<int> dp(n+1, 0); 
        
        // base case
        dp[0] = 0;
        dp[1] = 0;
        
        for (int i=2; i<=n; ++i)
        {
            dp[i] = std::min(dp[i-2]+cost[i-2] , dp[i-1]+cost[i-1]);
        }
        
        return dp[n];
    }
};