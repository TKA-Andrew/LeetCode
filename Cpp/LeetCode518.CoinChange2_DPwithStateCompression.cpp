// time complexity: O(N*amount)
// space complexity: O(amount)

#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        int N = coins.size();
        std::vector<int> dp(amount+1, 0);
        
        // base case
        dp[0] = 1;
        
        for (int i=1;i<=N;i++) {
            for (int j=1; j<=amount; j++) {
                if (j-coins[i-1]>=0) {
                    dp[j] = dp[j] + dp[j-coins[i-1]];
                }
            }
        }
        
        return dp[amount];
    }
};