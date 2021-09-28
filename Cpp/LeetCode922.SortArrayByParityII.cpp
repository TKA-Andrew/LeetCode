// reference: https://leetcode.com/problems/sort-array-by-parity-ii/discuss/1490847/C%2B%2B-Two-pointers-solution

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
        int evenIdx = 0;
        int oddIdx = 1;
        const int n = nums.size();
        while (evenIdx<n && oddIdx<n) {
            if (nums[evenIdx]%2 == 0) {
                evenIdx += 2;
            } else if (nums[oddIdx]%2 != 0) {
                oddIdx += 2;
            } else {
                std::swap(nums[oddIdx], nums[evenIdx]);
            }
        }
        return nums;
    }
};