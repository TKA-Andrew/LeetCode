// This is a bottom up approach using Dynamic Programming
// Time Complexity: O(nk) , where k is numbder of coins
// Space Complexity: O(n)

#include <algorithm> // for min()
#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        // dp[i] means the minimum number of coins needed to achieve the target i amount
        dp[0] = 0; // base case
        for (int i = 1; i <= amount; i++) {
            for (auto coin : coins) {
                if ((i - coin) < 0) continue; // invalid to proceed
                dp[i] = std::min(dp[i], dp[i-coin] + 1); // + 1 is for the coin used in "- coin" expression
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};