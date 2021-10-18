#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int res = INT_MIN;
        std::vector<int> dp(n, 0);
        dp[0] = nums[0];
        
        for (int i = 1; i<n; i++) {
            dp[i] = std::max(nums[i], nums[i] + dp[i-1]);
        }
        
        for (int i = 0; i<n; i++) {
            res = std::max(res, dp[i]);
        }
        
        return res;
    }
};