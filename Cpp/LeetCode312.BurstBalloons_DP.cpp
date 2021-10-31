// time complexity: O(N^3)
// space complexity: O(N^2)

#include <vector>

class Solution {
public:
    int maxCoins(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> points(n+2, 0);
        points[0] = points[n+1] = 1;
        for (int i=1;i<=n;i++){
            points[i] = nums[i-1];
        }
        std::vector<std::vector<int>> dp(n+2, std::vector<int> (n+2,0));
        
        for (int i=n; i>=0; i--) {
            for (int j=i+1; j<n+2; j++) {
                for (int k=i+1; k<j; k++) {
                    dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k][j] + points[i]*points[k]*points[j]);
                }
            }
        }
        
        return dp[0][n+1];
        
    }
};