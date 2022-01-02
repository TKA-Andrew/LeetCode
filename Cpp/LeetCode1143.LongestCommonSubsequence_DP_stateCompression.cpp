// O(MN) time
// O(N) space

#include <vector>
#include <string>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int M = text1.size();
        int N = text2.size();
        
        // DEFINITION OF DP
        /*
            dp[i][j] means the longest common subsequence (LCS) for text1[0..i-1] and text2[0..j-1]
            for example:
                input: text1="aecde", text2="ace"
                
                        j   0   1   2   3   4   5
                            ''  a   e   c   d   e
                i        --------------------------
                0   ''  |   0   0   0   0   0   0
                1   a   |   0   1   1   1   1   1
                2   c   |   0   1   1   2   2   2
                3   e   |   0   1   2   2   2   3
        */
        // hence, our final answer should be dp[M][N];
        // std::vector<std::vector<int>> dp(M+1, std::vector<int> (N+1, 0));
        std::vector<int> dp(N+1, 0);
        
        // BASE CASE
        // dp[0][*] = 0;
        // dp[*][0] = 0;
        
        // CHOICES
        /*
            1) forms longer LCS by adding 1(when text1[i-1] == text2[j-1])
            2) dont form longer LCS (when text1[i-1] != text2[j-1])
        */
        
        // STATE TRANSITION
        /*
                        { 0, if (i==0 || j==0)
            dp[i][j] =  { dp[i-1][j-1] + 1, if (text1[i-1] == text2[i-1])
                        { max(dp[i][j-1], dp[i-1][j]), if (text1[i-1] != text2[i-1])
        */
        
        // for (int i=1;i<=M;i++) {
        //     for (int j=1;j<=N;j++) {
        //         if (text1[i-1] == text2[j-1]) {
        //             dp[i][j] = dp[i-1][j-1] +1;
        //         } else {
        //             dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        //         }
        //     }
        // }
        
         for (int i=1;i<=M;i++) {
            int pre = 0; // equivalent to dp[i][0] = 0
            for (int j=1;j<=N;j++) {
                int temp  = dp[j]; // to store the dp[i-1][j-1] before dp[j] being updated
                if (text1[i-1] == text2[j-1]) {
                    dp[j] = pre +1;
                } else {
                    dp[j] = std::max(dp[j], dp[j-1]);
                }
                pre = temp; // in next loop, this will be equivalent to dp[i-1][j-1]
            }
        }

        return dp[N];
        
    }
};