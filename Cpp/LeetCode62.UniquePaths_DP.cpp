// Time Complexity: O(MN)
// Space Complexity: O(MN)

#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int> (n, 1));
        
        // base case: all elements at dp[m-1][*] and dp[*][n-1] will equal to 1
        
        for (int i = m-2; i>=0; i--)
        {
            for (int j = n-2; j>=0; j--)
            {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }
};