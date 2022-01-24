#include <vector>
#include <math.h>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int n = nums.size() - 1 ;
        int i = 0;
        int j = nums.size() -1;
        std::vector<int> ret(nums.size(), 0);
        while (i<=j && n>=0) {
            if (abs(nums[j])> abs(nums[i])) {
                ret[n] = nums[j]*nums[j];
                j--;
            } else {
                ret[n] = nums[i]*nums[i];
                i++;
            }
            n--;
        }
        return ret;
    }
};