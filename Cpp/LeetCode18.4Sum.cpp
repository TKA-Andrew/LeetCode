#include <vector>
#include <algorithm> // for sort()

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int> > res;
        int N = nums.size(); 
        std::sort(nums.begin(),nums.end());
    
        for (int i = 0; i < N; i++) {
        
            int sum3target = target - nums[i];
        
            for (int j = i + 1; j < N; j++) {
            
                int sum2Target = sum3target - nums[j];
            
                int left = j + 1;
                int right = N - 1;
            
                while(left < right) {
                
                    int two_sum = nums[left] + nums[right];
                
                    if (two_sum < sum2Target) left++;
                
                    else if (two_sum > sum2Target) right--;
                
                    else {
                    
                        std::vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[left];
                        quadruplet[3] = nums[right];
                        res.push_back(quadruplet);
                    
                        while (left < right && nums[left] == quadruplet[2]) ++left;
                    
                       
                        while (left < right && nums[right] == quadruplet[3]) --right;
                
                    }
                }
                
                while(j + 1 < N && nums[j + 1] == nums[j]) ++j;
            }
        
            while (i + 1 < N && nums[i + 1] == nums[i]) ++i;
        
        }
    
        return res;
    }
};