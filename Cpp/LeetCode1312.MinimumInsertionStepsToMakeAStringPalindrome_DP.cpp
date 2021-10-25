// using Dynamic Programming (Dp Table)
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

#include <vector>
#include <string>

class Solution {
public:
    int minInsertions(std::string s) {
        // definition of dp: 
        //      dp[i][j] is the mininum insertions needed for substring s[i..j]
        
        // final answer should be dp[0][n-1]
        
        // base case:
        //  1) when i == j, means only 1 character, and no insertion needed, hence, dp[i][j] = 0
        //  2) i>j is not a valid subsequence, should be equal to 0
        
        // state transtition:
        // 1) if s[i]==s[j], no insertion needed, hence dp[i][j] = dp[i+1][j-1]
        // 2) if s[i]!=s[j], 1 or 2 insertions needed. hence dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1
        
        int stringSize = s.size();
        std::vector<std::vector<int>> dp(stringSize, std::vector<int> (stringSize, 0)); // initialize all to zero
        
        for (int i=stringSize-2; i>=0; i--) {
            for (int j=i+1; j<stringSize; j++) {
                if (s[i]==s[j]) {
                    dp[i][j] = dp[i+1][j-1];    
                } else {
                    dp[i][j] = std::min(dp[i+1][j], dp[i][j-1]) + 1;
                }
            }
        }
        
        return dp[0][stringSize-1];
    }
};