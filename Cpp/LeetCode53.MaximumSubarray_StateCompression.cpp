// using Dynamic Programming with State Compression
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int prev = nums[0];
        int res = nums[0];
        
        for (int i = 1; i<n; i++) {
            prev = std::max(nums[i], nums[i] + prev);
            res = std::max(res, prev);
        }
        
        return res;
    }
};