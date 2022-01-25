#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int left=0;
        int n = nums.size();
        int right = 1;
        while (left<n && right<n) {
            if (nums[left]==0 && nums[right]!=0) {
                std::swap(nums[left], nums[right]);
                left++;
                right++;
            } else {
                if (nums[left] != 0 ) {
                    left++;
                }
                right++;
            }
        }
    }
};