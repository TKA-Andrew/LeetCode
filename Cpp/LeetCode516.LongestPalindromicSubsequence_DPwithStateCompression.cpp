// using Dynamic Programming (Dp Table)
// Time Complexity: O(n^2)
// Space Complexity: O(n)

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
        
        std::vector<int> dp(stringSize, 1); // initialize all to 1

        
        for (int i=stringSize-2; i>=0; i--) {
            int pre = 0; // to store dp[i+1][j-1], and reset it after moving to new i
            for (int j=i+1; j<stringSize; j++) {
                int temp = dp[j]; // to store previous dp[j]
                if (s[i]==s[j]) {
                    // dp[i][j] = dp[i+1][j-1] + 2;                    
                    dp[j] = pre + 2;
                } else {
                    // dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    dp[j] = std::max(dp[j], dp[j-1]);                 
                }
                pre = temp; // to store previous dp[j]
            }
        }
        
        return dp[stringSize-1];
        
    }
};