#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<int> track;
        std::vector<bool> used(nums.size(),false);
        backtrack(nums, track, used);
        return res;
    }
    
    void backtrack(std::vector<int>& nums, std::vector<int>& track, std::vector<bool>& used) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                track.push_back(nums[i]); 
                backtrack(nums,track,used);
                used[i] = false;
                track.pop_back();
            }
        }
    }
};