// O(N^2) time
// O(N) space
// this solution is not efficient, but it is based on 2Sum


#include <vector>
#include <algorithm> // for sort()

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int idx = 0;
        int N = nums.size();
        int target = 0;
        std::vector<std::vector<int>> res;
            
        while (idx<N) {
            int required = target - nums[idx];
            auto tuples = twoSumTarget(nums, idx+1, required);
            for (auto tuple: tuples) {
                tuple.push_back(nums[idx]);
                res.push_back(tuple);
            }
            int currentValue = nums[idx];
            while (idx<N && nums[idx]==currentValue) {
                idx++;
            }
        }
        return res;
    }
    
    std::vector<std::vector<int>> twoSumTarget(std::vector<int>& nums, int start, int target) {
        int left = start;
        int right = nums.size()-1;
        std::vector<std::vector<int>> ans;
        while (left<right) {
            int sum = nums[left] + nums[right];
            int leftValue = nums[left];
            int rightValue = nums[right];
            if (target>sum) {
                while (left<right && nums[left]==leftValue) {
                    left++;
                }
            } else if (target<sum) {
                while (left<right && nums[right]==rightValue) {
                    right--;
                }
            } else{
                ans.push_back({nums[left], nums[right]});
                while (left<right && nums[left]==leftValue) {
                    left++;
                }
                while (left<right && nums[right]==rightValue) {
                    right--;
                }
            }
        }
        return ans;
    }
};