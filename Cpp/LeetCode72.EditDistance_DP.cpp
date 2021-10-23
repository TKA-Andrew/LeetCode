#include <vector>
#include <string>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.size();
        int n = word2.size();
        
        /*
        w1/w2   ''  'a' 'p' 'p' 'l' 'e'
        ''       0   1   2   3   4   5 
        'r'      1   1   2   3   4   5
        'a'      2   1   2   3   4   5
        't'      3   2   2   3   4   5   
        */
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1));
        
        // base case
        for (int i=0; i<=m; i++) {
            dp[i][0] = i;
        }
        for (int j=0; j<=n; j++) {
            dp[0][j] = j;
        }
        
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = std::min(dp[i-1][j-1] + 1, 
                                   std::min(dp[i-1][j] + 1, dp[i][j-1] + 1));
                }
                
            }
        }
        
        return dp[m][n];
    }
};