#include <vector>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = 0;
        for (const auto num : nums) {
            sum += num;
        }
        if (sum%2!=0) {
            return false;
        }
        
        int N = nums.size();
        int W = sum/2;
        
        std::vector<std::vector<bool>> dp(N+1, std::vector<bool> (W+1, false) );
        
        // base case
        for (int n=0; n<=N; n++) {
            dp[n][0] = true;
        }
        
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=W; j++) {
                if (j-nums[i-1] < 0) {
                    dp[i][j] = dp[i-1][j];                
                } else {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[N][W];
    }
};