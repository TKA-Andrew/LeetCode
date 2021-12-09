// O(N) time
// O(1) space

#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left<right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                std::vector<int> ans {left+1, right+1};
                return ans;
            } else if (target>sum) {
                left++;
            } else {
                right--;
            }
        }
        
        return {-1,-1};
    }
};