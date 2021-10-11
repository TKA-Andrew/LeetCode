#include <vector>
#include <iostream>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int max {0};
        int count {0};
        
        for(int num : nums) {
            if(num) {
                count++;
                if (count > max) {
                    max = count;
                }
            } else {
                count = 0;
            }
        }
        
        return max;
    }
};