// using Dynamic Programming (Dp Table)
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <vector>
#include <string>

class Solution {
public:
    int minInsertions(std::string s) {
        // definition of dp: 
        //      dp[j] is the mininum insertions needed for substring s[0..j]
        
        // final answer should be dp[n-1]
        
        // base case:
        //  1) when i == j, means only 1 character, and no insertion needed, hence, dp[j] = 0
        //  2) i>j is not a valid subsequence, should be equal to 0
        
        // state transtition:
        // 1) if s[i]==s[j], no insertion needed, hence dp[j] = previous dp[i+1][j-1]
        // 2) if s[i]!=s[j], 1 or 2 insertions needed. hence dp[j] = min(dp[j], dp[j-1]) + 1
        
        int stringSize = s.size();
        std::vector<int> dp(stringSize, 0);        
        
        for (int i=stringSize-2; i>=0; i--) {
            int pre = 0;
            for (int j=i+1; j<stringSize; j++) {
                int temp = dp[j];
                if (s[i]==s[j]) {
                    dp[j] = pre;    
                } else {
                    dp[j] = std::min(dp[j], dp[j-1]) + 1;
                }
                pre = temp;
            }
        }
        
        return dp[stringSize-1];
    }
};