// Time Complexity: O(nk) , where k is number of coins
// Space Complexity: O(n)

#include <vector>   

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        // DEFINITION OF DP
        /*
            d[i] means the minimum number of coin needed to achieve target i amount
            For example:
                input: coins = [2,5], amount = 11
                dp[0] = 0; // BASE CASE
                dp[1]= amount+1; // impossible
                dp[2] = 1; // 2
                dp[3] = amount+1; // impossible
                dp[4] = 2; // 2+2
                dp[5] = 1; // 1
                dp[6] = 3; // 2+2+2
                dp[7] = 2 // 5 + 2
                dp[8] = 4; // 2+2+2+2
                dp[9] = 3; // 5 + 2 + 2
                dp[10] = 2; // 5 + 5
                dp[11] = 4 // 5 + 2 + 2 + 2
        */
        // final answer = dp[amount]
        
        std::vector<int> dp(amount+1, amount+1);
        // here we actually can initialize all elements to INT_MAX
        // but amount+1 is enough to be the top boundary
        // and using INT_MAX will have problem when later comes to dp[i-coin] + 1
        
        // BASE CASE
        dp[0] = 0;
        
        // CHOICES
        // - coins[i] for(int i=0;i<N;i++) if (target-coins[i] > 0)
        
        // STATE TRANSITION
        /*
        dp[i] = { 0, i = 0
                { INT_MAX, if (i-coins[j])<0
                { min(dp[i], dp[i-coins[j]]+1), if (i-coins[j]) >= 0
        */
        
        for (int i=0;i<=amount;i++) {
            for (const auto coin:coins) {
                if (i - coin < 0) {
                    continue; // invalid to proceed
                }
                dp[i] = std::min(dp[i], dp[i-coin] + 1); // + 1 is for the coin used in "- coin" expression
            }
        }
        
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};