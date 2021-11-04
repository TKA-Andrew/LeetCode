// time complexity: O(N)
// space complexity: O(1)

#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int N = nums.size();
        if (N==1) return nums[0];
        return std::max(robRange(nums,0,N-2), robRange(nums,1, N-1));
    }
    
    // modified from LeetCode 198
    int robRange(std::vector<int>& nums, int start, int end) {        
        int dp_iplus2 = 0;
        int dp_iplus1 = 0;
        int dp_i = 0;
        
        // we need to start from the back, because base case is from the back
        for (int i = end; i>=start; i--) {
            dp_iplus2 = dp_iplus1;
            dp_iplus1 = dp_i;
            dp_i = std::max(dp_iplus1 , nums[i] + dp_iplus2);
        }
        
        return dp_i;
    }
};