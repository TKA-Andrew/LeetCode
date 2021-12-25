// O(N) time
// O(1) space

#include <vector>
#include <climits> // for INT_MIN and INT_MAX

class Solution {
public:
    int findUnsortedSubarray(std::vector<int>& nums) {
        int N = nums.size();
        int smallest = INT_MAX;
        int biggest = INT_MIN;
        
        if (N<=1) {
            return 0;
        }
        
        for (int i=0;i<N;i++) {
            if (isOutOfOrder(i, nums)) {
                smallest = std::min(smallest, nums[i]);
                biggest = std::max(biggest, nums[i]);
            }
        }
        
        if (smallest == INT_MAX) {
            return 0;
        }
        
        int leftIdx = 0;
        while (smallest >= nums[leftIdx]) {
            leftIdx++;
        }
        
        int rightIdx = N-1;
        while (biggest <= nums[rightIdx]) {
            rightIdx--;
        }
        
        return rightIdx-leftIdx+1;
    }
    
    bool isOutOfOrder(int i, std::vector<int>& nums) {
        if (i==0) {
		    return nums[i] > nums[i+1];
        }
        if (i==nums.size()-1) {
            return nums[i] < nums[i-1];
        }
        return nums[i]<nums[i-1] || nums[i]>nums[i+1];
    }
};