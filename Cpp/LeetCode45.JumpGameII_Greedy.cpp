// O(N) time
// O(1) space

#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int N = nums.size();
        int end = 0;
        int farthest = 0;
        int jump = 0;
        for (int i=0; i<N-1; i++) {
            farthest = std::max(farthest, i+nums[i]);
            if (end == i) { // if reached ending idx, check which is the next farthest end
                jump++;
                end = farthest;
            }
        }
        return jump;
    }
};