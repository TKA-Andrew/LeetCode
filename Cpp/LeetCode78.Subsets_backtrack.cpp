#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> res;
    
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }
    
    void backtrack(std::vector<int>&nums, int start, std::vector<int>& track) {
        res.push_back(track);
        for (int i=start; i<nums.size(); i++) {
            track.push_back(nums[i]);
            backtrack(nums, i+1, track);
            track.pop_back();
        }
    }
};