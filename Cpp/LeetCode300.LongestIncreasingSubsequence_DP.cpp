// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        
        int N = nums.size();
        if (N==0) return 1;
        
        // DEFINITION OF DP
        /*
            dp[i] means the subsequence length for subsequence ending with ith element
            for example:
                input: nums = [0,1,0,3,2,3,1]
                dp[0] = 1; // [0]
                dp[1] = 2; // [0, 1]
                dp[2] = 1; // [0]
                dp[3] = 3; // [0, 1, 3]
                dp[4] = 3; // [0, 1, 2] 
                dp[5] = 4; // [0, 1, 2 ,3]
                dp[6] = 2; // [0, 1]
        */
        // hence, our answer will not be dp[N-1]
        std::vector<int> dp(N, 1); // initialize all to 1 as minimum will be 1
        
        // BASE CASE
        dp[0] = 1;
        
        // CHOICES
        /*
            1) forms LIS with previous elements
            2) dont form LIS with previous elements
            
            choice 2 can be neglected because choice 1 definitely will be greater than choice 2
            
            for choice 1,
                the nested choices will be the (0..j)th elements where j<i
        */
        
        // STATE TRANSITION
        /*
                    { 1, if i >=0 && dont form LIS with the (0..i)th elements
            dp[i] = { dp[i], if i >=1 && nums[i] <= nums[j]
                    { max(dp[i], dp[j] + 1), if i>=1 && nums[i] > nums[j]
        */
        
        for (int i=1;i<N;i++) {
            for (int j=0;j<i;j++) {
                if (nums[i] > nums[j]) { //can form LIS
                    dp[i] = std::max(dp[i], dp[j] + 1); // +1 is to include the ith element
                }
            }
        }
        
        int res = dp[0];
        for (int i=1;i<N;i++) {
            res = std::max(res, dp[i]);
        }
                    
        return res;
    }
};