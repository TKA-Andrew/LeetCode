// time complexity: O(N)
// space complexity: O(1)

#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int N = nums.size();
        
        int dp_iplus2 = 0;
        int dp_iplus1 = 0;
        int dp_i = 0;
        
        // we need to start from the back, because base case is from the back
        for (int i = N-1; i>=0; i--) {
            dp_iplus2 = dp_iplus1;
            dp_iplus1 = dp_i;
            dp_i = std::max(dp_iplus1 , nums[i] + dp_iplus2);
        }
        
        return dp_i;
        
    }
};