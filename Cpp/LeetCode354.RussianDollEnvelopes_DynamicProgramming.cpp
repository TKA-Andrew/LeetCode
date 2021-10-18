// using Dynamic Programming
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <vector>
#include <algorithm> // for sort()

class Solution {
public:
    
    // Solution of LeetCode300
    int lengthOfLIS(std::vector<int>& nums) {
        
        int numSize = nums.size();
        std::vector<int> dp(numSize, 1);
        int res = 0;
        
        for (int i = 0; i<numSize; i++) {
            for (int j = 0; j<i ; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        
        for (int i = 0; i<numSize; i++) {
            res = std::max(res, dp[i]);
        }
        
        return res;
    }
    
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        
        // For an envelope to fit into another envelope, both height and width must be smaller
        // Hence, we can solve 50% of the problem by sorting according to width
        // Then, for envelopes with same width, we sort the envelopes according to their height in descending order
        // An example of sorted vector:
        /*
            [1, 8]
            [2, 3]
            [5, 4]
            [5, 2]
            [6, 7]
            [6, 4]
        */
       // With the width sorted in ascending order but height sorted in descending order,
       // finding LIS at the height we can get the max number of envelopes we can Russian doll

 
        auto cmp = [](const auto& a, const auto& b) { 
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
        };
        std::sort(envelopes.begin(), envelopes.end(), cmp);
        
        std::vector<int> height; 
        
        for (auto item:envelopes) {
            height.push_back(item[1]); 
        }
        return lengthOfLIS(height);
    }
};