// Time Complexity: O(logN)
// Space Complexity: O(1)

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (nums[mid] == target)
            {
                return mid;
            } else if (nums[left] <= nums[mid]) // LHS sorted or nums[left] == nums[right]
            {
                if (target<nums[mid] && target>=nums[left])
                {
                    right = mid - 1;
                } else
                {
                    left = mid + 1; // not within the left hand range, go to right hand
                }
            } else if (nums[mid] < nums[right]) // RHS sorted
            {
                if (target>nums[mid] && target<=nums[right])
                {
                    left = mid + 1;
                } else {
                    right = mid - 1; // not within RHS, go to LHS
                }
            }
        }
        return -1;
    }
};