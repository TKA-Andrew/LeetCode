#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        int N = coins.size();
        std::vector<std::vector<int>> dp(N+1, std::vector<int> (amount+1, 0));
        
        // dp definition
        // dp[i][j] means when there is i coins used and target is j, there are dp[i][j] combinations
        
        // dp[0][...] = 0; // Base case: when no coin used, 0 combination
        // dp[...][0] = 0; // Base case: when target amount is 0, only 1 possible combination
        
        for (int i=1; i<=N; i++) {
            dp[i][0] = 1; // Base case: when target amount is 0, only 1 possible combination
        }
        
        for (int i=1;i<=N;i++) {
            for (int j=1; j<=amount; j++) {
                if (j-coins[i-1]>=0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];                    
                }
            }
        }
        
        return dp[N][amount];
    }
};