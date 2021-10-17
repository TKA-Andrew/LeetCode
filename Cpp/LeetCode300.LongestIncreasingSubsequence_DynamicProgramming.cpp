#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        
        int numSize = nums.size();
        std::vector<int> dp(numSize, 1);
        int res = 0;
        
        for (int i = 0; i<numSize; i++) {
            for (int j = 0; j<i ; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        
        for (int i = 0; i<numSize; i++) {
            res = std::max(res, dp[i]);
        }
        
        return res;
    }
};