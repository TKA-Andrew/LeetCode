// time complexity: O(N)
// space complexity: O(N)

#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int N = nums.size();
        
        // dp definition: 
        // dp[i] means the maximum amount of money we can rob starting from ith house
        
        // base case
        // dp[n] = dp[n+1] = 0 
        
        std::vector<int> dp(N+2, 0);
        
        // we need to start from the back, because base case is from the back
        for (int i = N-1; i>=0; i--) {
            dp[i] = std::max(dp[i+1] , nums[i] + dp[i+2]);
        }
        
        return dp[0];
        
    }
};