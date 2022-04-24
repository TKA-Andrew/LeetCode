// Time Complexity: O(N)
// Space Complexity: O(N)

#include <unordered_set>
#include <vector>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> s;
        
        for (auto num:nums)
        {
            s.insert(num);
        }
        
        int ans = 0;
        
        for (auto num:nums)
        {
            if (!s.count(num-1)) // to ensure the consecutive sequence will not be processed again
            {
                int count = 1;
                int find = num+1;
                while (s.count(find))
                {
                    find++;
                    count++;
                }
                ans = std::max(ans, count);
            }
        }
        return ans;
    }
};