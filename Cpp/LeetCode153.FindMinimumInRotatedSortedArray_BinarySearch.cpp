#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int N = nums.size();
        
        int left = 0;
        int right = N-1;
        
        while (left<right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            } else
            {
                right = mid;
            }
        }
        return nums[left]; // return nums[left] and nums[right] is the same
    }
};