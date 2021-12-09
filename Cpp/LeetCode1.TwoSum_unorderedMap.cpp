// O(N) time
// O(N) space

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int,int> indexRecord;
        int N = nums.size();
        std::vector<int> ans;
        for (int i=0;i<N;i++) {
            int need = target - nums[i];
            if (indexRecord.count(need)>0) {
                ans.push_back(i);
                ans.push_back(indexRecord[need]);
                return ans;
            } else {
                indexRecord[nums[i]] = i;
            }
        }
        return ans;
    }
};