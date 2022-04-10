// Time Complexity: O(N)
// Space Complexity: O(1)

#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int N = nums.size();
        
        int prevMax = nums[0];
        int prevMin = nums[0];
        int ans = prevMax;
        
        for (int i = 1; i<N; i++)
        {
            int tempPrevMax = prevMax; // since prevMax will be updated before prevMin
            prevMax = std::max(tempPrevMax*nums[i], prevMin*nums[i]);
            prevMax = std::max(nums[i], prevMax);
            prevMin = std::min(tempPrevMax*nums[i], prevMin*nums[i]);
            prevMin = std::min(nums[i], prevMin);
            ans = std::max(prevMax, ans);
        }
        return ans;
    }
};