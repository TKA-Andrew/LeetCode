// Time Complexity: O(logN)
// Space Complexity: O(1)

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        while(left<=right) {
            int mid = left + (right-left)/2; // equivalent to (left+right)/2, to prevent overflow
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        return -1;
    }
};