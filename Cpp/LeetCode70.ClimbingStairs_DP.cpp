// O(N) time
// O(N) space

#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n==0 || n==1) return 1;
        
        // DEFINITION OF DP
        /*
            dp[i] means the number of distinct ways to reach ith level
            For example:
                input: n = 4
                dp[1] = 1 // 1
                dp[2] = 2 // 1+1, 2
                dp[3] = 3 // 1+1+1, 2+1, 1+2
                dp[4] = 5 // 1+1+1+1, 2+1+1, 2+2, 1+2+1, 1+1+2
                dp[5] = 8 // 1+1+1+1+1, 2+1+1+1, 2+2+1, 2+1+2,
                          // 1+2+2, 1+2+1+1, 1+1+2+1, 1+1+1+2
        */
        
        std::vector<int> dp(n+1, 0);
        
        // BASE CASE
        dp[0] = 1;
        dp[1] = 1;
        
        // CHOICES
        // - climb 1 step
        // - climb 2 steps
        
        // STATE TRANSITION
        // dp[i] =  { 1, n = 0, 1
        //          { dp[i-2] + dp[i-1], n>=1
        
        for (int i = 2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};