// O(N) time
// O(N) space

#include <vector>

class Solution {
public:
    int fib(int n) {

        if (n==0) return 0;
        
        // MEANING OF DP
        // dp[i] means the nth fibonacci number
        std::vector<int> dp(n+1, 0);

        // BASE CASE
        dp[0] = 0;
        dp[1] = 1;
        
        // STATE TRANSITION, 
        //          { 0, i = 0
        // dp[i] =  { 1, i = 1
        //          { dp[i-1] + dp[i-2], i>=2
        
        // CHOICE
        // for this question, no selection involed
        
        for (int i=2;i<=n;i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};



