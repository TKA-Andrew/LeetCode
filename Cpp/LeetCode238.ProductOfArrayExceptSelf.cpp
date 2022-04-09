#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int N = nums.size();
        std::vector<int> answer(N, 1);
        
        // from left to right
        for (int i=1; i<N; i++)
        {
            answer[i] = answer[i-1] * nums[i-1]; 
            // answer now stores cumulative product from left
        }
        
        // from right to left
        for (int i=N-2; i>=0; --i)
        {
            nums[i] *= nums[i+1]; 
            // nums now stores cumulative product from right
            
            // cumulative product of left * cumulative product of right
            // will get product of array except self
            answer[i] = nums[i+1] * answer[i];
        }
        
        return answer;
    }
};