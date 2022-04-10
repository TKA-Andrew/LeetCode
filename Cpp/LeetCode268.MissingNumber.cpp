#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int N = nums.size();
        int totalSum = N*(N+1)/2; 
        int arrSum = 0;
        for (const auto num:nums) {
            arrSum += num;
        }
        return totalSum - arrSum;
    }
};