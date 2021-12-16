// O(N) time
// O(N) space

#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> presum;
        presum.insert(std::make_pair(0,1));
        
        int ans=0;
        int sum0_i = 0;
        for (int i=0;i<n;i++) {
            sum0_i += nums[i];
            int sum0_j = sum0_i - k;
            if (presum.count(sum0_j)>0) {
                ans += presum[sum0_j];
            }
            if (presum.count(sum0_i)>0) {
                presum[sum0_i] += 1;
            } else{
                presum[sum0_i] = 1;
            }
        }
        
        return ans;
    }
};