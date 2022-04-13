// Time Complexity: O(target*N)
// Space Complexity: O(target+1)

#include <vector>

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        int N = nums.size();
        std::vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        
        for (int i=1; i<=target; i++)
        {
            for (const auto num:nums)
            {
                if (i < num)
                {
                    continue;
                }
                dp[i] += dp[i-num];
            }
        }
        
        return dp[target];
    }
};