// O(N) time
// O(1) space

#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int N = nums.size();
        int farthest = 0;
        for (int i=0;i<N-1;i++) { // no need to jump at last index
            farthest = std::max(farthest, i+nums[i]);
            if (farthest <= i) {
                return false;
            }
        }
        return farthest >= N-1;
    }
};