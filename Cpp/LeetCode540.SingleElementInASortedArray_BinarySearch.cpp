// using Binary Search to achieve O(logN) time complexity
// Time complexity: O(logN)
// Space Complexity: O(1)

#include <vector>

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        if (right==0) {
            return nums[0];
        }
        while (left<=right) {
            int mid = left + (right-left)/2;
            if (mid == 0) { // this happens when the single element is at index 0
                return nums[mid];
            }
            if (nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid]) {
                return nums[mid];
            } else if (mid%2 == 0) { // if mid index is even
                if (nums[mid] == nums[mid+1]) { //
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (mid%2 != 0) { // if mid index is odd
                if (nums[mid] == nums[mid-1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};