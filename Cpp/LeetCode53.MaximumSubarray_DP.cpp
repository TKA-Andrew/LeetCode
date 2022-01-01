// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <climits>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
int N = nums.size();        
        if (N==0) return 0;
        
        // MEANING OF DP
        /*
            dp[i] is the maximum sum of subarray ending with ith element
            For example: 
                Input array : [-2, 1, -3, 4]
                dp[0] = -2 , our subarray is [-2]
                dp[1] = 1 , our subarray is [-2]
                dp[2] = -2 , our subarray is [1,-3] 
                dp[4] = 4 , our subarray is [4]
        */
        std::vector<int> dp(N, 0);

        // BASE CASE
        dp[0] = nums[0];
        
        // CHOICES
        // - The ith element forms a new subarray
        // - The ith element joins previous subarray which has last element at index i-1
        
        // STATE TRANSITION, 
        //          { nums[0], n = 0
        // dp(i) =  { nums[i], if ( nums[i] > nums[i] + dp[i-1]) && n>=1
        //          { dp[i-1] + nums[i], if ( nums[i] <= nums[i] + dp[i-1]) && n>=1
        
        for (int i=1;i<N;i++) {
            if (nums[i] >= nums[i] + dp[i-1]) {
                dp[i] = nums[i];
            } else {
                dp[i] = dp[i-1] + nums[i];
            }
        }
        
        // find the largest dp[i]
        int res = dp[0];
        for (int i=1;i<N;i++) {
            res = std::max(dp[i], res);
        }
        
        return res;
    }
};