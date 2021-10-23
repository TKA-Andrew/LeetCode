// using Dynamic Programming (Dp Table)
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

#include <vector>
#include <string>

class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        // definition of dp: 
        //      dp[i][j] is the longest palindromic subsequence for substring s[i..j]
        
        // final answer should be dp[0][n-1]
        
        // base case:
        //  1) when i == j, means only 1 character, and the palindromic subsequence length can only be 1
        //  2) i>j is not a valid subsequence, should be equal to 0
        
        // state transition:
        //  1) if s[i] == s[j], dp[i][j] = dp[i+1][j-1] + 2
        //  2) if s[i] !== s[j], dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        
        /*
        i/j     'b' 'a' 'b' 'y'
        'b'      1   1   3   3  
        'a'      0   1   1   1 
        'b'      0   0   1   1 
        'y'      0   0   0   1    
        */
        
        int stringSize = s.size();
        
        std::vector<std::vector<int>> dp(stringSize, std::vector<int> (stringSize, 0)); // initialize all to zero
        
        for (int i=0;i<stringSize;i++){
            dp[i][i] = 1;
        }
        
        for (int i=stringSize-2; i>=0; i--) {
            for (int j=i+1; j<stringSize; j++) {
                if (s[i]==s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;                    
                } else {
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][stringSize-1];
        
    }
};