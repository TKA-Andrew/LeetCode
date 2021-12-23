// O(N) time
// O(1) space

#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int N = nums.size();
        if (N==0) {
            return 0;
        }
        int slow = 0;
        int fast = 1;
        while (fast<N) {
            if (nums[fast] != nums[slow]) {
                nums[slow+1] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow+1;
    }
};