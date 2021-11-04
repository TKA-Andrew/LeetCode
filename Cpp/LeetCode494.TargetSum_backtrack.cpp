#include <vector>

class Solution {
public:
    int res = 0;
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int N = nums.size();
        if (N == 0) return 0;
        backtrack(nums, 0, target);
        return res;
    }
    
    void backtrack(std::vector<int>& nums, int i, int remaining) {
        int N = nums.size();
        if (i == N) {
            if (remaining == 0) {
                res++;
            }
            return;
        }
        
        remaining += nums[i];
        backtrack(nums, i+1, remaining);
        remaining -= nums[i];
        
        remaining -= nums[i];
        backtrack(nums, i+1, remaining);
        remaining += nums[i];
    }
};