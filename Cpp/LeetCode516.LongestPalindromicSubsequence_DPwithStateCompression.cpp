// using Dynamic Programming (Dp Table)
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <vector>
#include <string>

class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        // definition of dp: 
        //      dp[j] is the longest palindromic subsequence for substring s[0..j]
        
        // final answer should be dp[n-1]
        
        // base case:
        //  1) when i == j, means only 1 character, and the palindromic subsequence length can only be 1
        //  2) i>j is not a valid subsequence, should be equal to 0
        
        // state transition:
        //  1) if s[i] == s[j], dp[i][j] = previousDp[i+1][j-1] + 2 // 
        //  2) if s[i] !== s[j], dp[i][j] = max(dp[j], dp[j-1])
        
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
            int pre = 0; 
            for (int j=i+1; j<stringSize; j++) {
                int temp = dp[j];
                if (s[i]==s[j]) {
                    dp[j] = pre + 2;
                } else {
                    dp[j] = std::max(dp[j], dp[j-1]);                 
                }
                pre = temp;
            }
        }
        
        return dp[stringSize-1];
        
    }
};